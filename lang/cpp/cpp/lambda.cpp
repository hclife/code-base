#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

int main()
{
	std::vector<int> c{1,2,3,4,5,6,7};
	int x=5;
	c.erase(std::remove_if(c.begin(),c.end(),
		[x](int n){return n<x;}),c.end());
	std::cout<<"c: ";
	for (auto i:c) {
		std::cout<<i<<' ';
	}
	std::cout<<'\n';

#if 0
	auto func1=[](int i){return i+4;};
	std::cout<<"func1: "<<func1(6)<<'\n';
#endif

	return 0;
}
