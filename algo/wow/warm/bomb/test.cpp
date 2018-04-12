//bomb explosion - test.cpp
// DD NOT INCLUDE ANY FILES

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
struct point queue[SIZE];
const int a[]={0,0,1,-1};
const int b[]={1,-1,0,0};

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
