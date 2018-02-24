#include<memory>
#include<iostream>
#include<vector>

template<typename T, unsigned N>
std::size_t len(T (&)[N]) {
	return N;
}

template<typename T>
typename T::size_type len(T const& t) {
	return t.size();
}

int main(int argc, char* argv[])
{
	int a[10];
	std::vector<int> v;
	std::cout << len(a) << std::endl;
	std::cout << len("tmp") << std::endl;
	std::cout << len(v) << std::endl;
	std::allocator<int> x;
	return 0;
}
