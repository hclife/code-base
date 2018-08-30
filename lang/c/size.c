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

typedef struct H {
    char x;
    short y;
    int z;
} H;

typedef struct I {
    char x;
    int y;
    short z;
} I;


int main() {
    printf("%lu\n",sizeof(A)); //0
    printf("%lu\n",sizeof(B)); //8
    printf("%lu\n",sizeof(C)); //8
    printf("%lu\n",sizeof(D)); //12
    printf("%lu\n",sizeof(E)); //12
    printf("%lu\n",sizeof(F)); //8
    printf("%lu\n",sizeof(G)); //12
    printf("%lu\n",sizeof(H)); //8
    printf("%lu\n",sizeof(I)); //12

    return 0;
}
