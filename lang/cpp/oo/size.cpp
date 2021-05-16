#include <iostream>
#include <cstdlib>
using namespace std;

class A {
};

int main() {
	int a[]={1,2,3};
	void *p=malloc(10);
	int *q=a;
	cout<<sizeof(a)<<endl;
	cout<<sizeof(p)<<endl;
	cout<<sizeof(q)<<endl;
	cout<<sizeof(A)<<endl;
	if (p) free(p);
	return 0;
}
