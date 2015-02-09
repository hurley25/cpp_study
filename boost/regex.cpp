#include <locale>
#include <iostream>
#include <string>

#include <boost/regex.hpp>

int main(int argc, char *argv[])
{
	std::locale loc;

	std::cout << loc.name() << std::endl;

	std::string s = "Boris Schaling";
	boost::regex expr("\\w+\\s\\w");

	std::cout << boost::regex_match(s, expr) << std::endl;

	boost::smatch what;

	if (boost::regex_search(s, what, expr)) {
		std::cout << what[0] << std::endl;
	}

	boost::regex expr2("\\s");
	std::string format = "_";

	std::cout << boost::regex_replace(s, expr2, format) << std::endl;

	return 0;
}
