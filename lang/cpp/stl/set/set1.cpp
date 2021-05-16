#include <set>
#include <iostream>
using namespace std;

int main() {
	set<int> s;
	//for (int i=1;i<=3;++i) s.insert(i);
	for (int i=3;i>=1;--i) s.insert(i);
	s.insert(1);
	for (auto it=s.begin();it!=s.end();++it)
		cout<<*it<<' ';
	cout<<endl;
	cout<<"count(1)="<<s.count(1)<<endl;
	cout<<"count(4)="<<s.count(4)<<endl;
	return 0;
}
