#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
using namespace std;

int main()
{
	char c; string s;
	ifstream in("2-7-ShowLine.cpp");
	while (1) {
		//if ((c=getchar())!='\n') continue;
		if ((c=cin.get())!='\n') continue;
		if (getline(in,s)) cout<<s;
		else break;
	}
	return 0;
}
