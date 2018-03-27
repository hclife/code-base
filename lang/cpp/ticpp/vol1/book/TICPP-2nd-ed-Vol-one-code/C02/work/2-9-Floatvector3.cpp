#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<float> x,y,z;
	for (int i=0;i<25;i++) x.push_back(i+10.5);
	for (int i=0;i<25;i++) y.push_back(i*20.5);
	for (int i=0;i<25;i++) z.push_back(x[i]+y[i]);

	cout<<"x: ";
	for (int i=0;i<x.size();i++) cout<<x[i]<<" ";
	cout<<endl;

	cout<<"y: ";
	for (int i=0;i<y.size();i++) cout<<y[i]<<" ";
	cout<<endl;

	cout<<"z: ";
	for (int i=0;i<z.size();i++) cout<<z[i]<<" ";
	cout<<endl;

	return 0;
}
