//c++11	std::initializer_list example
#include <iostream>
#include <vector>
using namespace std;

class MyNumber
{
    public:
	MyNumber(const std::initializer_list<int> &v) {
	    for (auto itm : v) {
		mVec.push_back(itm);
	    }
	}

	void print() {
	    for (auto itm : mVec) {
		std::cout << itm << " ";
	    }
	    cout<<endl;
	}
    private:
	std::vector<int> mVec;
};

int main()
{
    MyNumber m = { 1, 2, 3, 4 };
    m.print();  // 1 2 3 4

    return 0;
}
