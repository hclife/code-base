#include <bits/stdc++.h>
using namespace std;

int main() {
	//string s="1 23 # 4";
	string s="1,23,4,56,32";
	stringstream ss(s);
	/*
	while (ss>>s) {
		//cout<<s<<endl;
		//int v=convert<int>(s);
		int v=atoi(s.c_str());
		cout<<v<<endl;
	}
	*/
	int v;char c;
	while (ss>>v) {
		cout<<v<<endl;
		ss>>c;
	}
	return 0;
}
