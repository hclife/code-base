#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
	vector<int> v;
	v.push_back(13);
	v.push_back(23);
	v.push_back(03);
	v.push_back(233);
	v.push_back(113);
	sort(v.begin(),v.end());
	for (int i=0;i<v.size();++i) {
		cout<<v[i]<<' ';
	}
	cout<<endl;
	return 0;
}
