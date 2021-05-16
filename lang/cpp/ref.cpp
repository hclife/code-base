#include <iostream>
using namespace std;

int main() {
	int i=5;
	int &k=i;
	k=6;
	cout<<i<<endl;
	cout<<k<<endl;
	return 0;
}
