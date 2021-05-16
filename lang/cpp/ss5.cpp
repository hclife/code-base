#include <iostream>
#include <sstream>
using namespace std;

int main() {
	stringstream ss;ss<<"456";
	int first;ss>>first;
	cout<<first<<endl;

	ss.clear();ss<<true;
	int second;ss>>second;
	cout<<second<<endl;

	return 0;
}
