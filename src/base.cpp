#include<iostream>
#include<typeinfo>

#include "base.hpp"

template<typename T>
void print(T const& t)
{
	std::cout << typeid(t).name() << std::endl;
}
