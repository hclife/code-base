#include <iostream>
#include <cstdarg>
#include "fun.h"
using namespace std;

#define FUN_ARGS			\
	va_list args;			\
	va_start(args,count);		\
	for (int i=0;i<count;++i)	\
	cout<<va_arg(args,int)<<" ";	\
	cout<<endl;			\
	va_end(args);

void funv(int count,...)
{
	cout<<"void_fun"<<endl;
	FUN_ARGS;
}

char func(int count,...)
{
	cout<<"char_fun"<<endl;
	FUN_ARGS;
	return 'x';
}

int funi(int count,...)
{
	cout<<"int_fun"<<endl;
	FUN_ARGS;
	return 0;
}

float funf(int count,...)
{
	cout<<"float_fun"<<endl;
	FUN_ARGS;
	return 1.2f;
}
