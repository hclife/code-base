//bomb explosion
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

#define SIZE		10004
#define rint		register int
#define queue_init	(head=tail=0)
#define queue_is_empty	(head==tail)
#define enqueue(x)	(queue[tail++]=(x))
#define dequeue		(queue[head++])

struct point {
    unsigned int x,y;
    unsigned int time;
};

int head,tail;
static struct point queue[SIZE];
static const int a[]={0,0,1,-1};
static const int b[]={1,-1,0,0};

unsigned int counting(int map[100][100]) {
    int ans=0;
    for (rint i=0;i<100;++i)
    for (rint j=0;j<100;++j)
    if (map[i][j]) ++ans;
    return ans;
}

unsigned int test_main(int map[100][100], unsigned int x, unsigned int y) {
    if (!map[x][y]) return counting(map);
    struct point in,out;queue_init;
    map[in.x=x][in.y=y]=0;in.time=0;
    enqueue(in);
    while (!queue_is_empty) {
	out=dequeue;
	if (out.time>=10) continue;
	for (int k=0;k<4;++k) {
	    int i=out.x+a[k],j=out.y+b[k];
	    if (i<0 || i>=100 || j<0 || j>=100) continue;
	    if (map[i][j]==1) {
		map[in.x=i][in.y=j]=0;
		in.time=out.time+1;
		enqueue(in);
	    }
	}
    }
    return counting(map);
}


