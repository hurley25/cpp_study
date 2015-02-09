#include <iostream>
#include <vector>

#include <boost/interprocess/managed_shared_memory.hpp>

int main(int argc, char *argv[])
{
	boost::interprocess::managed_shared_memory managed_shm(
							boost::interprocess::open_or_create, "Highscore", 1024);

	int *a = managed_shm.construct<int>("Integer")(99);

	std::cout << *a << std::endl;

	std::pair<int *, std::size_t> p = managed_shm.find<int>("Integer");

	if (p.first) {
		std::cout << *(p.first) << " " << p.second << std::endl;
	}

	return 0;
}
