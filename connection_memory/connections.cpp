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

awaitable<void> connect(boost::asio::io_context& io_context, tcp::endpoint ep, int& step)
{
	tcp::socket s(io_context);
	boost::asio::socket_base::receive_buffer_size option(256 * 1024);
	s.set_option(option);

	co_await wait_until(io_context, [&](){return step == 1;});
	std::cout << "connecting" << std::endl;
	co_await s.async_connect(ep, boost::asio::use_awaitable);

	co_await wait_until(io_context, [&](){return step == 2;});
	std::cout << "writing" << std::endl;
	std::string req = "GET / HTTP/1.1\r\n\r\n";
	const size_t written_bytes = co_await boost::asio::async_write(s, boost::asio::const_buffer(req.data(), req.length()), boost::asio::use_awaitable);

	co_await wait_until(io_context, [&](){return step == 3;});
	std::cout << "reading" << std::endl;
	static char buf[10240];
	const size_t read_bytes = co_await boost::asio::async_read(s, boost::asio::mutable_buffer(buf, sizeof(buf)), boost::asio::use_awaitable);
	buf[read_bytes] = '\0';
	std::cout << buf << std::endl;
}

int main()
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
    tcp::resolver::results_type endpoints = resolver.resolve("www.baidu.com", "80");
	const int N = 1;	
	for (int i = 0; i < N; i++)
	{ 	
		co_spawn(io_context, connect(io_context, *endpoints.begin(), step), detached);
	}
	
	io_context.run();
}

