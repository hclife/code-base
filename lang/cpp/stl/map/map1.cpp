#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
	map<int, string> mapStudent;
	mapStudent.insert(pair<int,string>(1,"student_one"));
	mapStudent.insert(pair<int,string>(2,"student_two"));
	mapStudent.insert(pair<int,string>(3,"student_three"));

	//sequential iterator
	map<int,string>::iterator itor;
	for (itor=mapStudent.begin();itor!=mapStudent.end();++itor)
		cout<<itor->first<<" "<<itor->second<<endl;

	cout<<endl;

	//reversal iterator
	map<int,string>::reverse_iterator ritor;
	for (ritor=mapStudent.rbegin();ritor!=mapStudent.rend();++ritor)
		cout<<ritor->first<<" "<<ritor->second<<endl;

	//search key for value
	itor=mapStudent.find(1);
	if (itor!=mapStudent.end())
		cout<<"Find the value is "<<itor->second<<endl;

	return 0;
}
