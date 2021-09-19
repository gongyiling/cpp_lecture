#include <boost/asio/co_spawn.hpp>
#include <boost/asio/detached.hpp>
#include <boost/asio/io_context.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/signal_set.hpp>
#include <boost/asio/write.hpp>
#include <boost/asio.hpp>
#include <iostream>
#include <chrono>

using boost::asio::ip::tcp;
using boost::asio::awaitable;
using boost::asio::co_spawn;
using boost::asio::detached;
using boost::asio::use_awaitable;

template <typename pred_t>
awaitable<void> wait_until(boost::asio::io_context& io_context, pred_t pred)
{
	while (!pred())
	{
		boost::asio::deadline_timer timer(io_context);
		timer.expires_from_now(boost::posix_time::milliseconds(100));
		co_await timer.async_wait(boost::asio::use_awaitable);
	}
}

awaitable<void> connect(boost::asio::io_context& io_context, tcp::endpoint local_ep, tcp::endpoint remote_ep, bool receive, int& step)
{
	tcp::socket s(io_context);
	s.open(tcp::v4());
	s.bind(local_ep);

	co_await wait_until(io_context, [&](){return step == 1;});

	std::cerr << "connecting" << std::endl;
	co_await s.async_connect(remote_ep, boost::asio::use_awaitable);

	co_await wait_until(io_context, [&](){return step == 2;});
	if (receive) 
	{
		std::cerr << "receiving" << std::endl;
		char buf[1024];
		const size_t read_bytes = co_await s.async_read_some( 
			boost::asio::mutable_buffer(buf, sizeof(buf)), 
			boost::asio::use_awaitable);
		buf[read_bytes] = '\0';
		std::cerr << buf << std::endl;
	}
	else
	{
		std::cerr << "sending" << std::endl;
		std::string req = "hello, world.";
		const size_t written_bytes = co_await boost::asio::async_write(s, 
			boost::asio::const_buffer(req.data(), req.length()), 
			boost::asio::use_awaitable);
	}

	co_await wait_until(io_context, [&](){return step == 3;});
}

int main(int argc, char* argv[])
{
	try
	{
		boost::asio::io_context io_context;
		
		boost::asio::signal_set signals(io_context, SIGINT, SIGTERM);

		int step = 0;
		std::function<void (const boost::system::error_code&, int)> signal_handle = [&](const boost::system::error_code&, int)
		{ 
			if (step < 3) 
			{
				step++;
				signals.async_wait(signal_handle);
			}
			else
			{ 
				io_context.stop(); 
			}
		};

		signals.async_wait(signal_handle);

		tcp::resolver resolver(io_context);
    	tcp::resolver::results_type endpoints1 = resolver.resolve("192.168.3.38", "8000");
    	tcp::resolver::results_type endpoints2 = resolver.resolve("192.168.3.38", "8080");
		tcp::endpoint ep1 = *endpoints1.begin();
		tcp::endpoint ep2 = *endpoints2.begin();
		co_spawn(io_context, connect(io_context, ep1, ep2, false, step), detached);
		co_spawn(io_context, connect(io_context, ep2, ep1, true, step), detached);
		
		io_context.run();
	}
	catch(std::exception& e)
  	{
    	std::cerr << "Exception: " << e.what() << "\n";
  	}
	return 0;
}

