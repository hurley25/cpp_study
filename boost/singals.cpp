#include <iostream>

#include <boost/signals.hpp>

void func1()
{
	std::cout << __FUNCTION__ << std::endl;
}

void func2()
{
	std::cout << __FUNCTION__ << std::endl;
}

int main(int argc, char *argv[])
{
	boost::signal<void ()> s;

	s.connect(&func1);
	s.connect(&func2);

	std::cout << "num_solts: " << s.num_slots() << std::endl;

	if (!s.empty()) {
		s();
	}

	s.disconnect_all_slots();

	return 0;
}