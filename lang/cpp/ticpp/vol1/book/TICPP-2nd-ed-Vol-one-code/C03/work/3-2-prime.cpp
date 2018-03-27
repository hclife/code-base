#include <iostream>
using namespace std;

int main()
{
	cout<<"2 ";
	for (int x=3;x<=100;x+=2) {
		int is_prime=1;
		for (int y=2;y*y<=x;++y) {
			if (x%y==0) {
				is_prime=0;
				break;
			}
		}
		if (is_prime) cout<<x<<" ";
	}
	cout<<endl;
	return 0;
}
