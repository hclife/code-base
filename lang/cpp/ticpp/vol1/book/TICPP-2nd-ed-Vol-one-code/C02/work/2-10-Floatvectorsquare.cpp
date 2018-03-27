#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<float> v;
	for (int i=0;i<25;i++) v.push_back(i+5.3);
	for (int i=0;i<v.size();i++) cout<<v[i]<<" ";
	cout<<endl;
	for (int i=0;i<v.size();i++) v[i]*=v[i];
	for (int i=0;i<v.size();i++) cout<<v[i]<<" ";
	cout<<endl;
	return 0;
}
