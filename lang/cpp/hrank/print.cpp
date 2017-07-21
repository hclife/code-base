//Print Pretty
#include <iostream>
#include <iomanip> 
using namespace std;

int main() {
	int T; cin >> T;
	cout << setiosflags(ios::uppercase);
	cout << setw(0xf) << internal;
	while(T--) {
		double A; cin >> A;
		double B; cin >> B;
		double C; cin >> C;
        cout<<hex<<showbase<<nouppercase<<left<<(long long)(A)<<endl;
        cout<<dec<<noshowbase<<setfill('_')<<setw(0xf)<<right;
        cout<<showpos<<fixed<<setprecision(2)<<B<<endl;
        cout<<dec<<noshowbase<<noshowpos<<uppercase<<left;
        cout<<fixed<<setprecision(9)<<scientific<<C<<endl;
	}
	return 0;
}		