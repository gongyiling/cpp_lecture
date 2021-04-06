#include "user.pb.h"
#include <chrono>

int main()
{
	Role role;
	role.mutable_role_basic()->set_gold(1);
	const int N = 1000;
	for (int i = 0; i < N; i++)
	{
		auto* factory = role.mutable_factory_list()->add_factory_list();
		factory->set_id(i);
		factory->set_cd(10);
	}
	std::string data = role.SerializeAsString();
	printf("data.length()=%ld\n", data.length());

	const int M = 100000;
	Role role2;

	auto start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < M; i++)
	{
		role2.ParseFromString(data);
		role2.mutable_role_basic()->set_gold(role2.role_basic().gold() + 1);
		role2.SerializeToString(&data);
	}
	auto end = std::chrono::high_resolution_clock::now();

	printf("elapsed milliseconds: %ld\n", std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count());
	printf("data.length()=%ld, gold=%d, role2.factory_list_size()=%d\n", data.length(), role2.role_basic().gold(), role2.factory_list().factory_list_size());
	printf("role2.factory_list(10).id()=%d\n", role2.factory_list().factory_list(10).id());
	return 0;
}

