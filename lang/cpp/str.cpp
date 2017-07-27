#include <iostream>
using namespace std;

int main() {
	char str1[]="abc";
	char str2[]="abc";
	const char str3[]="abc";
	const char str4[]="abc";
	const char *str5="abc";
	const char *str6="abc";

	cout<<boolalpha<<(str1==str2)<<endl;
	cout<<boolalpha<<(str3==str4)<<endl;
	cout<<boolalpha<<(str5==str6)<<endl;

	return 0;
}
