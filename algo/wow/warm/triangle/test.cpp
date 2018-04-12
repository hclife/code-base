// maxsum of triangle - test.cpp
// DO NOT INCLUDE ANY FILES

#define SIZE		1000
#define rint		register int
#define maxv(x,y)	((x)>(y)?(x):(y))
#define minv(x,y)	((x)<(y)?(x):(y))

int sum;
char data[SIZE][SIZE];
const int a[]={0,0,1,-1};
const int b[]={1,-1,0,0};

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

