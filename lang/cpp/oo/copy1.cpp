#include <iostream>
using namespace std;

class CExample {
private:
	int a;
public:
	CExample(int b) {a=b;}
	CExample(const CExample &c) {a=c.a;}
	void Show() {cout<<a<<endl;}
};

int main() {
	CExample A(100);
	CExample B=A;
	B.Show();
	return 0;
}
