// maxsum of triangle
#include <stdio.h>
#include <stdlib.h>

#define SIZE   1000

static char map[10][SIZE][SIZE];
int run_test(const char map[SIZE][SIZE]);

static void build_space() {
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


#define rint		register int
#define maxv(x,y)	((x)>(y)?(x):(y))
#define minv(x,y)	((x)<(y)?(x):(y))

static int sum;
static char data[SIZE][SIZE];
static const int a[]={0,0,1,-1};
static const int b[]={1,-1,0,0};

void visit(int x,int y) {
    if (x<0 || x>=SIZE || y<0 || y>=SIZE) return;
    if (data[x][y]>1) sum+=data[x][y];
    data[x][y]=0;
    for (int k=0;k<4;++k) {
	int i=x+a[k],j=y+b[k];
	if (i<0 || i>=SIZE || j<0 || j>=SIZE) return;
	if (data[i][j]>0) visit(i,j);
    }
}

int run_test(const char map[SIZE][SIZE]) {
    int maxs=0;
    for (rint i=0;i<SIZE;++i)
    for (rint j=0;j<SIZE;++j) data[i][j]=map[i][j];
    for (rint i=0;i<SIZE;++i)
    for (rint j=0;j<SIZE;++j) {
	if (data[i][j]==1) {
	    sum=0;visit(i,j);
	    maxs=maxv(maxs,sum);
	}
    }
    // Return the largest sum of the numbers inside the triangles 
    return maxs;
}
