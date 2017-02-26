#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
	map<int,string> mapStudent;
	mapStudent[1]="student_one";
	mapStudent[2]="student_two";
	mapStudent[3]="student_three";
	mapStudent[3]="student_six";

	//sequential iterator
	map<int,string>::iterator itor;
	for (itor=mapStudent.begin();itor!=mapStudent.end();++itor)
		cout<<itor->first<<" "<<itor->second<<endl;
	
	cout<<endl;

	for (int idx=0;idx<mapStudent.size();++idx)
		cout<<idx<<" "<<mapStudent[idx]<<endl;

	return 0;
}
