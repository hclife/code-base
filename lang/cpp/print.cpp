#include <iostream>  
#include <iomanip>      
using namespace std;  
int main() {  
	double X=28.9877373733;
	cout<<int(X)<<endl;
	cout<<"0x"<<hex<<int(X)<<endl;
	cout<<scientific<<uppercase<<setprecision(10)<<X<<endl;

	cout<<endl;

	double PI=3.141592654;  
	cout<<PI<<endl;  
	cout<<setprecision(2)<<PI<<endl;  
	cout<<fixed<<setprecision(2)<<PI<<endl;   
	cout<<setfill('*')<<setw(20)<<setprecision(10)<<PI<<endl;  
	cout<<setfill('*')<<setw(20)<<setprecision(10)<<left<<PI<<endl;  
	cout<<scientific<<setprecision(10)<<PI<<endl;  
	cout<<scientific<<uppercase<<setprecision(10)<<PI<<endl;    
	return 0 ;  
}  
