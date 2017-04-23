//Pointer
#include <stdio.h>

#define ABS(x)    ((x)>=0?(x):-(x))

void update(int *a,int *b) {
    int sum=*a+*b;
    int absol=ABS(*a-*b);
    *a=sum;
    *b=absol;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}

