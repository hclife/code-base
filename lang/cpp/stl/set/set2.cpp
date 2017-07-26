#include <set>
#include <iostream>
using namespace std;

int main() {
	set<int> s;
	for (int i=1;i<=10;++i) s.insert(i);
	s.erase(s.begin());
	set<int>::iterator first=s.begin();
	set<int>::iterator second=first;
	++second;++second;
	s.erase(first,second);s.erase(8);
	set<int>::const_iterator it;
	for (it=s.begin();it!=s.end();++it) cout<<*it<<' ';
	cout<<endl;
	return 0;
}
