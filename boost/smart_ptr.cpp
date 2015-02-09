#include <iostream>

#include <boost/smart_ptr.hpp>

int main(int argc, char *argv[])
{
	// 作用域指针
	boost::scoped_ptr<int> i(new int);
	*i = 1;
	std::cout << *i << std::endl;

	i.reset(new int);
	*i.get() = 2;

	std::cout << *i << std::endl;

	// 作用域数组
	boost::scoped_array<int> array(new int[2]);
	*array.get() = 3;
	array[1] = 4;

	std::cout << array[0] << std::endl;
	std::cout << array[1] << std::endl;

	// 共享指针
	boost::shared_ptr<int> is(new int(5));
	boost::shared_ptr<int> isc = is;
	std::cout << *is << std::endl;
	(*is)++;
	std::cout << *isc << std::endl;

	// 共享数组
	boost::shared_array<int> arrays(new int[2]);
	*arrays.get() = 7;
	arrays[1] = 8;

	std::cout << arrays[0] << std::endl;
	std::cout << arrays[1] << std::endl;

	// 弱指针 weak_ptr
	// boost::weak_ptr 必定总是通过 boost::shared_ptr 来初始化的
	// 一旦初始化之后，它基本上只提供一个有用的方法: lock()
	boost::weak_ptr<int> iw(is);
	boost::shared_ptr<int> ns = iw.lock();
	*ns = 9;
	std::cout << *is << std::endl;

	return 0;
}
