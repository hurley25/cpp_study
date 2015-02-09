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
		std::cout << name_ + " 析构鸟~" << std::endl;
	}
};


int main()
{
	std::shared_ptr<Data> data(new Data());
	data->name_ = "老数据";

	{
		std::shared_ptr<Data> data2 = data;
		{
			std::shared_ptr<Data> data_new(new Data(*data));
			data_new->name_ = "新数据";
			std::cout << "交换前  data 引用计数：" << data.use_count() << std::endl;
			std::cout << "交换前  data_new 引用计数：" << data_new.use_count() << std::endl;
			data.swap(data_new);
			std::cout << "交换后  data 引用计数：" << data.use_count() << std::endl;
			std::cout << "交换后  data_new 引用计数：" << data_new.use_count() << std::endl;
			Sleep(2000);
			std::cout << "data_new 析构" << std::endl;
		}
		Sleep(2000);
		std::cout << "data2 析构" << std::endl;
	}

	std::cout << "data 析构" << std::endl;

	return 0;
}
