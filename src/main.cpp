#include<typeinfo>
#include<type_traits>
#include<memory>
#include<iostream>
#include<vector>

#include "traits/hastype.hpp"
#include "base.hpp"

DEFINE_HAS_TYPE(value_type);
DEFINE_HAS_TYPE(char_type);

int main(int argc, char* argv[])
{
	std::cout << HasTypeT_value_type<int>::value << std::endl;
	std::cout << HasTypeT_value_type<std::vector<int>>::value << std::endl;
	return 0;
}
