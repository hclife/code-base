#include <iostream>
#include <string>
using namespace std;

int main()
{
	std::string str_dec="2001, A Space Odyssey";
	std::string str_hex="40c3";
	std::string str_bin="-10010110001";
	std::string str_auto="0x7f";
	std::string::size_type sz;

	int idec=std::stoi(str_dec,&sz);
	int ihex=std::stoi(str_hex,nullptr,16);
	int ibin=std::stoi(str_bin,nullptr,2);
	int iauto=std::stoi(str_auto,nullptr,0);

	std::cout<<str_dec<<": "<<idec<<" and ["<<str_dec.substr(sz)<<"]\n";
	std::cout<<str_hex<<": "<<ihex<<endl;
	std::cout<<str_bin<<": "<<ibin<<endl;
	std::cout<<str_auto<<": "<<iauto<<endl;

	return 0;
}
