#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
	ostringstream oss("abc");
	//oss.put('d');
	//oss.put('e');
	oss<<"fg";
	cout<<oss.str()<<endl;

	return 0;
}
