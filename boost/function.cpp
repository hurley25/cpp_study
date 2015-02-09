#include <iostream>

#include <boost/bind.hpp>
#include <boost/function.hpp>

struct World
{
	void hello(std::ostream &os)
	{
		os << "Hello World!" << std::endl;
	}
};

int main(int argc, char *argv[])
{
	boost::function<void (World *, std::ostream &)> f = &World::hello;

	World w;

	f(&w, boost::ref(std::cout));

	return 0;
}