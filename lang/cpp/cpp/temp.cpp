#include <iostream>
using namespace std;
int main(void)  
{  
	unsigned int const size1 = 2;  
	char str1[ size1 ];  
	int temp = 0;  
	cin >> temp;  
	int const size2 = temp;  
	char str2[ size2 ];  
	cout<<size2<<endl;
	cout<<sizeof(str2)<<endl;
	return 0;  
} 
