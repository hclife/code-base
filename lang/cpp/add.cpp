#include <iostream>
#include <cstdarg>
using namespace std;

int add(int count,...)
{
	int ret=0;
	va_list args;
	va_start(args,count);

	for (int i=0;i<count;++i) {
		int x=va_arg(args,int);
		//cout<<x<<endl;;
		ret+=x;
	}
	va_end(args);

	return ret;
}

int main()
{
	cout<<add(4,25,25,50,50)<<endl;
	return 0;
}
