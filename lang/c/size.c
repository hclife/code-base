#include <stdio.h>

typedef struct A {
} A;

typedef struct B {
    int a;
    char c;
    char b;
} B;

typedef struct C {
    long a;
    char b;
    char c;
} C;

typedef struct D {
    char a;
    int b;
    char c;
} D;

typedef struct E {
    char a;
    long b;
    char c;
} E;

typedef struct F {
    int x:5;
    int y:7;
    int z;
} F;

typedef struct G {
    int x:5;
    int y;
    int z:7;
} G;



int main() {
    printf("%lu\n",sizeof(A));
    printf("%lu\n",sizeof(B));
    printf("%lu\n",sizeof(C));
    printf("%lu\n",sizeof(D));
    printf("%lu\n",sizeof(E));
    printf("%lu\n",sizeof(F));
    printf("%lu\n",sizeof(G));
    return 0;
}
