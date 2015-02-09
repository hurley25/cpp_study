#include <iostream>

class C {
public:
	C() {}
	~C() {}

	C(C &c) { std::cout << "&" << std::endl; }

	C &operator=(C &c) { std::cout << "=" << std::endl; return c; }
};

int main()
{
	C c1, c2;

	c1 = c2;

	C c3(c1);

	return 0;
}
