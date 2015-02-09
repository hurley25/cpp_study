#include <iostream>

#include <boost/smart_ptr.hpp>

int main(int argc, char *argv[])
{
	// ������ָ��
	boost::scoped_ptr<int> i(new int);
	*i = 1;
	std::cout << *i << std::endl;

	i.reset(new int);
	*i.get() = 2;

	std::cout << *i << std::endl;

	// ����������
	boost::scoped_array<int> array(new int[2]);
	*array.get() = 3;
	array[1] = 4;

	std::cout << array[0] << std::endl;
	std::cout << array[1] << std::endl;

	// ����ָ��
	boost::shared_ptr<int> is(new int(5));
	boost::shared_ptr<int> isc = is;
	std::cout << *is << std::endl;
	(*is)++;
	std::cout << *isc << std::endl;

	// ��������
	boost::shared_array<int> arrays(new int[2]);
	*arrays.get() = 7;
	arrays[1] = 8;

	std::cout << arrays[0] << std::endl;
	std::cout << arrays[1] << std::endl;

	// ��ָ�� weak_ptr
	// boost::weak_ptr �ض�����ͨ�� boost::shared_ptr ����ʼ����
	// һ����ʼ��֮����������ֻ�ṩһ�����õķ���: lock()
	boost::weak_ptr<int> iw(is);
	boost::shared_ptr<int> ns = iw.lock();
	*ns = 9;
	std::cout << *is << std::endl;

	return 0;
}
