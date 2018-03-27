//: C02:Floatvector.cpp
// From Thinking in C++, 2nd Edition
// Available at http://www.BruceEckel.com
// (c) Bruce Eckel 2000
// Copyright notice in Copyright.txt
// Creating a vector that holds integers
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<float> v;
	for (int i=0;i<25;i++) v.push_back(i+10.5);
	for (int i=0;i<25;i++) cout<<v[i]<<" ";
	cout<<endl;
	return 0;
}
