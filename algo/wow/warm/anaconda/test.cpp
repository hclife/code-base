// longest anaconda - test.cpp

#define SIZE		1000
#define rint		register int
#define maxv(x,y)	((x)>(y)?(x):(y))
#define minv(x,y)	((x)<(y)?(x):(y))

int len;
char data[SIZE][SIZE];
const int a[]={0,0,1,-1};
const int b[]={1,-1,0,0};

void visit(int x,int y) {
    ++len;data[x][y]=0;
    for (int k=0;k<4;++k) {
	int i=x+a[k],j=y+b[k];
	if (i<0 || i>=SIZE || j<0 || j>=SIZE) return;
	if (data[i][j]) {visit(i,j);return;}
    }
}

int run_test(const char snake[SIZE][SIZE]) {
    int ans=0;
    for (rint i=0;i<SIZE;++i)
    for (rint j=0;j<SIZE;++j) data[i][j]=snake[i][j];
    for (rint i=0;i<SIZE;++i)
    for (rint j=0;j<SIZE;++j) if (data[i][j]) {
	len=0;visit(i,j);
	ans=maxv(ans,len);
    }
    return ans; // the length of longest anaconda
}

