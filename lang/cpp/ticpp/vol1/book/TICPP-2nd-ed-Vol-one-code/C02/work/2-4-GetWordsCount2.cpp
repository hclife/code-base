#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv)
{
	using namespace std;
	// process command-line arguments
	if (argc < 3) {
		cerr << "Usage: WordCount [word] [file]\n";
		return -1;
	}

	string word(argv[1]);
	ifstream file(argv[2]);
	long wcount=0;
	string token;
	while (file >> token)
		if (word == token) ++wcount;
	cout << "\"" << word << "\" appeared "
		<< wcount << " times.\n";
	return 0;
}
