// maxsum of triangle - main.cpp
#include <stdio.h>
#include <stdlib.h>
#define SIZE   1000

static char map[10][SIZE][SIZE];
extern int run_test(const char map[SIZE][SIZE]);

void build_space() {
	for (int count = 0; count < 10; count++) {
		for (int x = 0; x < SIZE; x++) 
                        for (int y = 0; y < SIZE; y++) map[count][x][y] = 0;

		for (int x = 0; x < 10; x++) {
			for (int y = 0; y < 10; y++) {
				int cx = x * 100 + (rand() % 10);
				int cy = y * 100 + (rand() % 10);

				int size = (rand() % 70) + 10;

				for (int pos = 0; pos <= size; pos++) {
					if (pos != size) {
						for (int p = 1; p < pos; p++) {
							map[count][cx+p][cy+pos] = (rand() % 10) + 2;
						} 
					}
					map[count][cx]      [cy + pos]  = 1;
					map[count][cx + pos][cy + size] = 1;
					map[count][cx + pos][cy + pos]  = 1;
				}
			}
		}
	}
}


int main() {
	build_space();
	for (int count = 0; count < 10; count++)
		printf("%d\n", run_test(map[count]));
	return 0;
}

