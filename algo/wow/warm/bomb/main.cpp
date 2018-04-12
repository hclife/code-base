//bomb explosion - main.cpp
#include <stdlib.h>
#include <stdio.h>

unsigned int test_main(int map[100][100], unsigned int x, unsigned int y);

static void build_data(int map[100][100]) {
    for (int x = 0; x < 100; x++ )
        for( int y = 0; y < 100; y++ )
            map[x][y] = ((rand() % 3) != 0) ? 1 : 0;
}


int main() {
    int map[100][100];
    for (int l = 0; l < 10; l++) {
        build_data(map);
        printf("%d\n", test_main(map, rand() % 100, rand() % 100));
    }
    return 0;
}



