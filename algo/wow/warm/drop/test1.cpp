// maximum drop height - test.cpp
// DD NOT INCLUDE ANY FILES

#define SIZE	    100
#define maxv(x,y)   ((x)>=(y)?(x):(y))

int test(int data[SIZE]) {
    int map[SIZE][SIZE];
    for (int i=0;i<SIZE;++i)
    for (int j=0;j<SIZE;++j) map[i][j]=0;

    //construct map from data
    for (int j=0;j<SIZE;++j) {
	for (int i=SIZE-1;i>=0;--i) {
	    if (data[j]<=0) break;
	    map[i][j]=1;
	    data[j]--;
	}
    }

    //rotate map
    int _map[SIZE][SIZE];
    for (int i=0;i<SIZE;++i)
    for (int j=0;j<SIZE;++j)
    _map[j][SIZE-1-i]=map[i][j];

    //apply gravity
    int ans=0;
    for (int j=0;j<SIZE;++j) {
	int maxh=0;
	for (int i=0;i<SIZE;++i)
	if (_map[i][j]) {
	    maxh=SIZE-i;
	    break;
	}
	if (maxh<=0) continue;

	int boxs=0;
	for (int i=0;i<SIZE;++i)
	if (_map[i][j]) ++boxs;

	int drop=maxh-boxs;
	ans=maxv(ans,drop);
    }

    //after rotation and applying gravity,
    //return the maximum drop height.
    return ans;
}
