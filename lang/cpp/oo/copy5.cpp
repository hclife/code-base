//shallow copy
#include <iostream>

class Rect {
public:
    Rect() {p=new int(100);}
    ~Rect() {if (p) delete p;}
private:
    int width;
    int height;
    int *p;
};

int main() {
    Rect rect1;
    Rect rect2(rect1);
    return 0;
}
