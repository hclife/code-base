//C++ Class Template Specialization
#include <iostream>
using namespace std;
enum class Fruit { apple, orange, pear };
enum class Color { red, green, orange };

template <typename T> struct Traits;

// Define specializations for the Traits class template here.
template <>
struct Traits<Color> {
public:
    static string name(int x) {
        if (x==0) return "red";
        if (x==1) return "green";
        if (x==2) return "orange";
        return "unknown";
    }
};

template <>
struct Traits<Fruit> {
public:
    static string name(int x) {
        if (x==0) return "apple";
        if (x==1) return "orange";
        if (x==2) return "pear";
        return "unknown";
    }
};    

int main() {
	int t = 0; std::cin >> t;
    for (int i=0; i!=t; ++i) {
        int index1; std::cin >> index1;
        int index2; std::cin >> index2;
        cout << Traits<Color>::name(index1) << " ";
        cout << Traits<Fruit>::name(index2) << "\n";
    }
}
    