#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
	map<int,string> mapStudent;
	mapStudent.insert(map<int,string>::value_type(1,"student_one"));
	mapStudent.insert(map<int,string>::value_type(2,"student_two"));
	mapStudent.insert(map<int,string>::value_type(3,"student_three"));

	map<int,string>::iterator itor;
	for (itor=mapStudent.begin();itor!=mapStudent.end();++itor)
		cout<<itor->first<<" "<<itor->second<<endl;

	return 0;
}
