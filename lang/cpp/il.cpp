//c++11 std::initializer_list
#include <iostream>
class CompareClass {
public:
    CompareClass(int,int) {}
    CompareClass(std::initializer_list<int>) {}
};

int main() {
    CompareClass foo{10,20}; //calls initializer_list constructor
    CompareClass bar(10,20); //calls the first constructor
    return 0;
}
