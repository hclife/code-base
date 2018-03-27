#include <iostream>
using namespace std;

typedef enum Color {
    COLOR_RED,	    //0
    COLOR_GREEN,    //1
    COLOR_BLUE,	    //2
    COLOR_YELLOW,   //3
    COLOR_PURPLE,   //4
    COLOR_PINK,	    //5
    COLOR_BLACK,    //6
    COLOR_MAX,
} Color;

int main() {
    for (int i=0;i<COLOR_MAX;++i) cout<<i<<' ';
    cout<<endl;
    return 0;
}

