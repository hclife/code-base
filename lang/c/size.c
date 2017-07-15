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

int main() {
    printf("%lu\n",sizeof(A));
    printf("%lu\n",sizeof(B));
    printf("%lu\n",sizeof(C));
    printf("%lu\n",sizeof(D));
    printf("%lu\n",sizeof(E));
    return 0;
}
