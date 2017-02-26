#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
	stringstream ss;
	int a=100;string s;
	ss<<a;ss>>s;cout<<s<<endl;

	ss.clear();
	string name="colinguan";
	char cname[200];
	ss<<name;ss>>cname;
	cout<<cname<<endl;

	return 0;
}

