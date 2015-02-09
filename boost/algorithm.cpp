#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

int main(int argc, char *argv[])
{
	std::vector<int> vect = {1, 2, 5, 6};
	int key = 5;
	auto result = std::find(vect.cbegin(), vect.cend(), key);
	std::cout << *result << std::endl;

	int sum = std::accumulate(vect.cbegin(), vect.cend(), 0);
	std::cout << sum << std::endl;

	std::vector<std::string> strVect = { "a", "b", "c", "d", "e" };
	std::string strSum = std::accumulate(strVect.cbegin(), strVect.cend(), std::string(""));
	std::cout << strSum << std::endl;

	std::vector<int> vect2 = { 1, 2, 5, 6 };
	std::cout << (vect == vect2) << std::endl;
	std::cout << std::equal(vect.cbegin(), vect.cend(), vect2.cbegin()) << std::endl;
	std::fill(vect2.begin(), vect2.end(), 0);
	std::cout << std::equal(vect.cbegin(), vect.cend(), vect2.cbegin()) << std::endl;

	std::fill_n(std::back_inserter(vect2), 6, 1);
	std::cout << vect2.size() << std::endl;

	std::replace(vect2.begin(), vect2.end(), 0, 2);

	std::vector<int> vectNew;
	std::replace_copy(vect2.cbegin(), vect2.cend(), std::back_inserter(vectNew), 2, 1);

	std::vector<std::string> words = { "the", "quick", "red", "fox",
				"jumps", "over", "the", "slow", "red", "turtle" };

	std::sort(words.begin(), words.end());
	auto end_unique = std::unique(words.begin(), words.end());
	words.erase(end_unique, words.end());

	for (std::string word : words) {
		std::cout << word << " ";
	}
	std::cout << std::endl;

	std::for_each(words.cbegin(), words.cend(),
			[](const std::string &str) {std::cout << str << " "; });
	std::cout << std::endl;

	auto add = [](int a, int b) -> int { return a + b; };
	std::cout << add(1, 2) << std::endl;

	int value1 = 2;
	int value2 = 4;
	auto add2 = [value1, value2](int a, int b) -> int { return a + b + value1 + value2; };
	std::cout << add2(1, 2) << std::endl;

	return 0;
}
