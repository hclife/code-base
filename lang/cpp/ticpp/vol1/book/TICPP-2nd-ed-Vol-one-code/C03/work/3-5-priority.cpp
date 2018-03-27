#include <iostream>
using namespace std;

int main() {
    int X,Y,Z;
    while (1) {
	cin>>X>>Y>>Z;
	int A=X+Y-2/2+Z;
	int B=X+(Y-2)/(2+Z);
	cout<<A<<' '<<B<<endl;
    }
    return 0;
}
