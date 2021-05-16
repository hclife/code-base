#include <set>
#include <iostream>
using namespace std;

int main() {
	set<int> s;
	for (int i=1;i<=3;++i) s.insert(i);
	s.insert(1);
	cout<<"size()="<<s.size()<<endl; //3
	cout<<"max_size()="<<s.max_size()<<endl;
	cout<<"begin()="<<*s.begin()<<endl; //1
	cout<<"end()="<<*s.end()<<endl; //3
	s.clear();
	cout<<"after clear:"<<endl;
	if (s.empty()) cout<<"set is null!"<<endl;
	cout<<"size()="<<s.size()<<endl; //0
	cout<<"max_size()="<<s.max_size()<<endl;
	return 0;
}
