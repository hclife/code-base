#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000

int run_test(const unsigned char cloud[SIZE][SIZE]);

static unsigned char cloud[10][SIZE][SIZE];

void build_cloud(void) {   
	for (int k = 0; k < 10; k++) {
		for(int j = 0; j < SIZE; j++)
			for(int i = 0; i < SIZE; i++)
				cloud[k][j][i] = 1;
		
		for(int i = 0; i < SIZE * 2; i++)
			cloud[k][rand() % SIZE][rand() % SIZE] = 0;
	}
}

int main() {
    build_cloud();
    for (int c = 0; c < 10; c++)
        printf("%d\n", run_test(cloud[c]));
    return 0;
}
