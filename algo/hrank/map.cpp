#include <iostream>
#include <string>
#include <map>
using namespace std;

#define rint	register int

int main()
{
	string key,value;
	int N;cin>>N;
	map<string,string> mapString;
	for (rint i=1;i<=N;++i) {
		cin>>key>>value;
		mapString.insert(map<string,string>::value_type(key,value));
	}

	map<string,string>::iterator itor;
#if 0
	for (itor=mapString.begin();itor!=mapString.end();++itor)
		cout<<itor->first<<" "<<itor->second<<endl;
#endif

	while (getline(cin>>ws,key)>0) {
		itor=mapString.find(key);
		if (itor!=mapString.end())
			cout<<key<<"="<<itor->second<<endl;
		else
			cout<<"Not found"<<endl;
	}

	return 0;
}
