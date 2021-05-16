//deep copy
#include <iostream>

class Rect {
public:
    Rect() {p=new int(100);}
    Rect(const Rect &r) {
	width=r.width;
	height=r.height;
	p=new int;
	*p=*(r.p);
    }
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
