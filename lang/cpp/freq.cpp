//count the frequency of each character in a string
#include <vector>
#include <string>
#include <cstdio>
#include <iostream>
using namespace std;

int main() {
#define rint	register int
    int T;cin>>T;
    const int max=128;
    for (rint t=1;t<=T;++t) {
	string s;cin>>s;
	size_t n=s.size();
	vector<size_t> count(max,0);
	for (rint i=0;i<n;++i) ++count[s[i]];
	printf("Case #%d\n",t);
	for (int c=0;c<max;++c)
	if (count[c]) printf("%c:%lu\n",c,count[c]);
    }
    return 0;
}
