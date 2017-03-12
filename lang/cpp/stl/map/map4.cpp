#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
	map<int,string> mapStudent;
	pair<map<int,string>::iterator,bool> ret;
	ret=mapStudent.insert(map<int,string>::value_type(1,"student_one"));
	if (ret.second==false) {
		cout<<"Insert student one failed"<<endl;
		return 1;
	}
	ret=mapStudent.insert(map<int,string>::value_type(2,"student_two"));
	if (ret.second==false) {
		cout<<"Insert student two failed"<<endl;
		return 2;
	}
	ret=mapStudent.insert(map<int,string>::value_type(3,"student_three"));
	if (ret.second==false) {
		cout<<"Insert student three failed"<<endl;
		return 3;
	}
	cout<<"Insert successfully"<<endl;

	map<int,string>::iterator itor;
	for (itor=mapStudent.begin();itor!=mapStudent.end();++itor)
		cout<<itor->first<<" "<<itor->second<<endl;

	return 0;
}
