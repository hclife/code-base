#include <iostream>
#include <vector>

int main() {
    std::vector<int> v;
    int sum(0);
    v.push_back(100);
    v.push_back(200);
    v.push_back(300);
    while (!v.empty()) {
	sum+=v.back();
	v.pop_back();
    }
    std::cout<<"The elements add upto "<<sum<<'\n';
    return 0;
}
