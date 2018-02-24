#ifndef BASE_HPP
#define BASE_HPP

template<typename T>
void print(T const& t)
{
	std::cout << typeid(t).name() << std::endl;
}

#endif
