#include <iostream>
#include <string>
#include <map>
#include <memory>
#include <windows.h>

class Data
{
public:
	std::string name_;

	~Data()
	{
		std::cout << name_ + " ������~" << std::endl;
	}
};


int main()
{
	std::shared_ptr<Data> data(new Data());
	data->name_ = "������";

	{
		std::shared_ptr<Data> data2 = data;
		{
			std::shared_ptr<Data> data_new(new Data(*data));
			data_new->name_ = "������";
			std::cout << "����ǰ  data ���ü�����" << data.use_count() << std::endl;
			std::cout << "����ǰ  data_new ���ü�����" << data_new.use_count() << std::endl;
			data.swap(data_new);
			std::cout << "������  data ���ü�����" << data.use_count() << std::endl;
			std::cout << "������  data_new ���ü�����" << data_new.use_count() << std::endl;
			Sleep(2000);
			std::cout << "data_new ����" << std::endl;
		}
		Sleep(2000);
		std::cout << "data2 ����" << std::endl;
	}

	std::cout << "data ����" << std::endl;

	return 0;
}
