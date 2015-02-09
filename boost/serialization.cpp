#include <iostream>
#include <fstream>
#include <string>

#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp> 

void save()
{
	std::ofstream file("archiv.txt");
	boost::archive::text_oarchive oa(file);
	std::string str = "Hello, Boost!";
	oa << str;
}

void load()
{
	std::ifstream file("archiv.txt");
	boost::archive::text_iarchive ia(file);
	std::string str;
	ia >> str;
	std::cout << str << std::endl;
}

int main(int argc, char *argv[])
{
	save();
	load();
}
