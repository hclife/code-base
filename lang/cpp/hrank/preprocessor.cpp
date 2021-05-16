//Preprocessor Solution
#include <iostream>
#include <vector>
using namespace std;

#define toStr(s)		#s
#define io(v)			cin>>v
#define foreach(v,i)		for (int i=0;i<v.size();++i)
#define INF			100000008
#define FUNCTION(func,cmp)	void func(int &x,int y) {if (y cmp x) x=y;}

#if !defined toStr || !defined io || !defined FUNCTION || !defined INF
#error Missing preprocessor definitions
#endif 

FUNCTION(minimum, <)
FUNCTION(maximum, >)

int main(){
	int n; cin >> n;
	vector<int> v(n);
	foreach(v, i) {
		io(v)[i];
	}
	int mn = INF;
	int mx = -INF;
	foreach(v, i) {
		minimum(mn, v[i]);
		maximum(mx, v[i]);
	}
	int ans = mx - mn;
	cout << toStr(Result =) <<' '<< ans;
	return 0;
}
