//: C02:Fillvector.cpp
// From Thinking in C++, 2nd Edition
// Available at http://www.BruceEckel.com
// (c) Bruce Eckel 2000
// Copyright notice in Copyright.txt
// Copy an entire file into a vector of string
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
	vector<string> v;
	ifstream in("2-6-Fillvector.cpp");
	string word;
	while (getline(in,word)) v.push_back(word);
	for (int i=0;i<v.size();i++) cout<<v[i]<<endl;
	return 0;
}
