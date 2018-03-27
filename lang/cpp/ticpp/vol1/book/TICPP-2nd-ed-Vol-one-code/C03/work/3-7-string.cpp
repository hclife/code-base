#include <string>
#include <iostream>
using namespace std;

//remove space from string with char*
string func1(char *s) {
    string t;
    while (*s) {
	if (*s!=' ') t+=*s;
	s++;
    }
    t+='\0';
    return t;
}

//remove space from string &
string func2(string &s) {
    string t;
    register int i,j;
    for (i=j=0;s[i];++i)
    if (s[i]!=' ') t+=s[i];
    t+='\0';
    return t;

}

int main() {
    int T;cin>>T;
    string s;
    while (T--) {
	getline(cin>>ws,s);
	//s=func1(&s[0]);
	s=func2(s);
	cout<<s<<endl;
    }
    return 0;
}
