// maximum drop height - test.cpp
// DD NOT INCLUDE ANY FILES

#define SIZE	    100
#define maxv(x,y)   ((x)>=(y)?(x):(y))

int test(int data[SIZE]) {
    int ans=0;
    for (int i=0;i<SIZE;++i) {
	int drop=0;
	for (int j=i+1;j<SIZE;++j)
	if (data[i]>data[j]) ++drop;
	ans=maxv(ans,drop);
    }
    return ans;
}
