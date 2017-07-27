#include <iostream>
using namespace std;
struct CLS  
{  
	int m_i;  
	CLS(int i): m_i( i )
	{
		cout<<"foo"<<i<<endl;
		cout<<m_i<<endl;
     	}  
	CLS()  
	{  
		CLS( 0 );  
	}  
};  

int main(void)  
{  
	CLS obj();  
	cout << obj.m_i << endl;  
	return 0;  
}  
