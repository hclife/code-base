#include <iostream>
#include <string>
using namespace std;

int wmap(const string s)
{
	if (s[0]>='0' && s[0]<='9')
		return s[0]-'0';
	if (s[0]>='a' && s[0]<='z')
		return s[0];
	if (s[0]>='A' && s[0]<='Z')
		return s[0];
	return -1;
}

int main()
{
	bool exit=false;
	string word;
	while (true) {
		cin>>word;
		int val=wmap(word);
		if (val<0) {
			cout<<"Input error"<<endl;
			continue;
		}
		if (val>=0 && val<=9) {
			cout<<word<<" is a number."<<endl;
			continue;
		}
		switch (val) {
		case 'e':
		case 'q':
		case 'E':
		case 'Q':
			cout<<"quit."<<endl;
			exit=true;
			break;
		case 'i':
		case 'I':
			cout<<word<<" is interesting..."<<endl;
			break;
		default:
			cout<<word<<" is normal..."<<endl;
			break;
		}
		if (exit==true) break;
	}
	return 0;
}
