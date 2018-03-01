#include<memory>
#include<iostream>
#include<vector>

#include "base.hpp"

struct X {
};

template<typename ...Types>
class Tuple {
public:
	static constexpr std::size_t len = sizeof...(Types);
};

int main(int argc, char* argv[])
{
	struct X x;
	std::cout << Tuple<int>::len << std::endl;
	std::cout << Tuple<int, int, int>::len << std::endl;
	return 0;
}
