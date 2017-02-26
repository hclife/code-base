#include <iostream>
#include <sstream>
using namespace std;

int main()
{
	istringstream iss("1 56.7");
	cout<<iss.str()<<endl;

	int a;iss>>a;
	cout<<a<<endl;

	float b;iss>>b;
	cout<<b<<endl;

	return 0;
}
