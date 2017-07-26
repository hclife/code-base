#include <set>
#include <iostream>
using namespace std;

int main() {
	int a[]={1,2,3};
	set<int> s(a,a+3);
	set<int>::const_iterator it;
	for (it=s.begin();it!=s.end();++it) cout<<*it<<' ';
	cout<<endl;
	pair<set<int>::iterator,bool> p=s.insert(5);
	if (p.second==true) cout<<*p.first<<endl;
	return 0;
}
