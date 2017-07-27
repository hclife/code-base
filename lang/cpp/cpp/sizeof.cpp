#include <iostream>
using namespace std;
void UpperCase( char str[] ) // 将str 中的小写字母转换成大写字母  
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

	cout << "str字符长度为: " << sizeof(str)/sizeof(str[0]) << endl;  

	UpperCase( str );  
	cout << str << endl;  
	return 0;  
}  
