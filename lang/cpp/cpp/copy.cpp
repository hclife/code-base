#include <iostream>
#include <string>

int main()
{
	char buf[20];
	std::string str("Test string...");
	std::size_t len=str.copy(buf,6,5);
	buf[len]=0;
	std::cout<<buf<<'\n';
	return 0;
}
