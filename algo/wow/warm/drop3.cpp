//maximum drop height

#include <stdio.h>
#include <stdlib.h>

int test(int data[100]);

void build_data(int data[100]) {
    for (int i = 0; i < 100; i++) {
        data[i] = rand() % 101; 
    }
}

int main() {
    int data[100];
    for (int l = 0; l < 10; l++) {
        build_data(data);
        printf("%d\n",test(data));
    }
    return 0;
}



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
