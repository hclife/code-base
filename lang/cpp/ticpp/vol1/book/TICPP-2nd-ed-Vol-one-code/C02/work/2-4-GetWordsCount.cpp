#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	vector<string> words;
	ifstream in("2-4-GetWordsCount.cpp");
	//ifstream in("2-2-CircleSize.cpp");
	string word,pattern;
	cout<<"Enter the pattern string: ";
	cin>>pattern;
	while (in>>word)
		if (word==pattern) words.push_back(word);
	//for (int i=0;i<words.size();i++)
	//cout<<i+1<<": "<<words[i]<<endl;
	cout<<"There are "<<words.size()<<" "
		<<pattern<<" words."<<endl;
	return 0;
}
