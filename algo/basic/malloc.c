#include <stdio.h>
#include <stdlib.h>

int main() {
    char *p=(char*)malloc(0);
    if (p==NULL) puts("a null pointer");
    else puts("a valid pointer");
    return 0;
}
