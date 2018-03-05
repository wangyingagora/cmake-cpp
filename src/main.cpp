#include<typeinfo>
#include<type_traits>
#include<memory>
#include<iostream>
#include<vector>

#include "base.hpp"

template<typename T>
void f(T)
{}

template<typename A>
void printParameterType(void (*)(A))
{
	std::cout << "Parameter type: " << typeid(A).name() << std::endl;
	std::cout << "- is int: " << std::is_same<A, int>::value << std::endl;
	std::cout << "- is const: " << std::is_const<A>::value << std::endl;
	std::cout << "- is pointer: " << std::is_pointer<A>::value << std::endl;
}

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

	printParameterType(&f<int>);
	printParameterType(&f<int const>);
	printParameterType(&f<int[7]>);
	printParameterType(&f<int(int)>);
	return 0;
}
