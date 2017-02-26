#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
	int i=1000;
	stringstream ss;ss<<i;
	string s;ss>>s;
	cout<<s<<endl;
	return 0;
}
