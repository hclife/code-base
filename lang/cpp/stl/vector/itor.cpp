#include <vector>
#include <iostream>
using namespace std;

int main() {  
	typedef vector<int> IntArray;
	IntArray array;
	array.push_back(1);
	array.push_back(2);
	array.push_back(2);
	array.push_back(3);
	IntArray::iterator itor;
	for(itor=array.begin();itor!=array.end();++itor) {  
		if(2 == *itor) array.erase(itor--);
	}  
	for (int i=0;i<array.size();++i) {
		cout<<array[i]<<endl;
	}
	return 0;
}
