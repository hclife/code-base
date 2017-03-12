#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
	stringstream ss("ccc");
	ss.put('d');
	ss.put('e');
	ss<<"fg";
	cout<<ss.str()<<endl;

	char a;ss>>a;
	cout<<a<<endl;

	return 0;
}
