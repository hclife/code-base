#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
	vector<string> v;
	v.push_back("king");
	v.push_back("usher");
	v.push_back("armstrong");
	v.push_back("texas");
	sort(v.begin(),v.end());
	for (int i=0;i<v.size();++i) {
		cout<<v[i]<<endl;
	}
	return 0;
}
