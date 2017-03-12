#include <iostream>
#include <sstream>
using namespace std;

int main() {
	stringstream ss;ss<<8888;
	char cs[8];ss>>cs;
	cout<<cs<<endl;
	return 0;
}
