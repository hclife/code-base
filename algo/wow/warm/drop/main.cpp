//maximum drop height - main.cpp
#include <stdio.h>
#include <stdlib.h>

int test(int data[100]);

void build_data(int data[100]) {
    for (int i = 0; i < 100; i++) {
        data[i] = rand() % 101; 
    }
}

int main() {
    int data[100];
    for (int l = 0; l < 10; l++) {
        build_data(data);
        printf("%d\n",test(data));
    }
    return 0;
}


