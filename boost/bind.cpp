#include <iostream>
#include <algorithm>
#include <vector>

#include <boost/bind.hpp>

void add(int i, int j)
{
	std::cout << i + j << std::endl;
}

void add(int i, int j, std::ostream &os)
{
	os << i + j << std::endl;
}

int main(int argc, char *argv[])
{
	std::vector<int> v;

	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	std::for_each(v.begin(), v.end(), boost::bind(add, 10, _1));

	// 当要用于 boost::bind() 的函数带有至少一个引用参数时，Boost.Ref 就很重要了
	// 由于 boost::bind() 会复制它的参数，所以引用必须特别处理

	std::for_each(v.begin(), v.end(), boost::bind(add, 10, _1, boost::ref(std::cout)));

	return 0;
}
