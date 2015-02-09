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

	// ��Ҫ���� boost::bind() �ĺ�����������һ�����ò���ʱ��Boost.Ref �ͺ���Ҫ��
	// ���� boost::bind() �Ḵ�����Ĳ������������ñ����ر���

	std::for_each(v.begin(), v.end(), boost::bind(add, 10, _1, boost::ref(std::cout)));

	return 0;
}
