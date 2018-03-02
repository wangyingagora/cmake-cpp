#include<memory>
#include<iostream>
#include<vector>

#include "base.hpp"

template<typename ...Types>
class Tuple {
public:
	static constexpr std::size_t len = sizeof...(Types);
};

template<typename T>
struct AccumTraits;

template<>
struct AccumTraits<char> {
	using Acct = int;
};

template<>
struct AccumTraits<short> {
	using Acct = int;
};

template<>
struct AccumTraits<int> {
	using Acct = long;
};

template<typename T>
auto accum(T const* beg, T const* end)
{
	using Acct = typename AccumTraits<T>::Acct;

	Acct total{};
	while(beg != end) {
		total += *beg;
		++beg;
	}
	return total;
}

int main(int argc, char* argv[])
{
	std::cout << Tuple<int>::len << std::endl;
	std::cout << Tuple<int, int, int>::len << std::endl;

	int num[] = {1, 2, 3, 4, 5};
	std::cout << "The average of int value is: " << accum(num, num + 5)/5 << std::endl;

	char name[] = "templates";
	int len = sizeof(name) - 1;
	std::cout << "The average of char value is: " << accum(name, name + len) / len << std::endl;
	return 0;
}
