#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	vector<string> words;
	ifstream in("2-3-GetWords.cpp");
	string word;
	while (in>>word) words.push_back(word);
	for (int i=0;i<words.size();i++)
		cout<<i+1<<": "<<words[i]<<endl;
	cout<<"There are "<<words.size()
	    <<" words separated by spaces."<<endl;
	return 0;
}
