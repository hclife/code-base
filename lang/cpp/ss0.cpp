//using stringstream to convert string
#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
using namespace std;

int main() {
	std::string s="152";
	int num1=std::atoi(s.c_str());
	cout<<num1<<endl;

	std::stringstream ss;int num2;
	ss<<s;ss>>num2;cout<<num2<<endl;

	return 0;
}
