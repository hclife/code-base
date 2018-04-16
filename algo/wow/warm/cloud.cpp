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

#define rint		register int
#define maxv(x,y)	((x)>(y)?(x):(y))
#define minv(x,y)	((x)<(y)?(x):(y))

int run_test(const unsigned char cloud[SIZE][SIZE]) {
    int ans=0,data[SIZE][SIZE]={0};
    for (rint i=0;i<SIZE;++i) data[i][0]=cloud[i][0];
    for (rint j=0;j<SIZE;++j) data[0][j]=cloud[0][j];
    for (rint i=1;i<SIZE;++i)
    for (rint j=1;j<SIZE;++j) if (cloud[i][j]) {
	    data[i][j]=minv(data[i-1][j],data[i][j-1]);
	    data[i][j]=minv(data[i][j],data[i-1][j-1])+1;
	    ans=maxv(ans,data[i][j]);
    }
    return ans; // Maxumum height of clouds
}
