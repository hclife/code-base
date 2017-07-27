#include <iostream>
using namespace std;
void toUpperCase(char str[])
{  
	//for( size_t i=0; i<sizeof(str)/sizeof(str[0]); ++i )  
	for (size_t i=0;str[i];++i)
	{  
		if( 'a'<=str[i] && str[i]<='z' )  
		{  
			str[i] -= ('a'-'A' );  
		}  
	}  
}  
int main(void)  
{  
	char str[] = "aBcDe";  
	cout << "str length:" << sizeof(str)/sizeof(str[0]) << endl;  
	toUpperCase( str );  
	cout << str << endl;  
	return 0;  
}
