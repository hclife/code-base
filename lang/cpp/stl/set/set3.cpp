#include <set>
#include <iostream>
using namespace std;

int main() {
	int a[]={1,2,3};
	set<int> s(a,a+3);
	set<int>::iterator it=s.find(2);
	if (it!=s.end()) cout<<*it<<endl;
	return 0;
}

