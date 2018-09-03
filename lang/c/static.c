#include <stdio.h>

int s_global;
static int global;

#define ARRAY_SIZE(A)	(sizeof(A)/sizeof(A[0]))

static int __calc(int a[],int len) {
    int temp;
    static int last;
    static int local;
    //static int last=len-1;  //error: initializer is not constant

    last=len-1;
    printf("__calc:len=%d,last=%d,local=%d\n",len,last,local);

    while (last>=0) {
	temp+=a[last];
	local+=a[last];
	global+=a[last];
	s_global+=a[last--];
    }

    printf("temp=%d,local=%d,",temp,local);
    printf("global=%d,s_global=%d\n",global,s_global);

    return 0;
}

static int calc(int a[]) {
    printf("calc:sizeof(a)=%d,sizeof(a[0])=%d\n", sizeof(a),sizeof(a[0]));
    __calc(a,ARRAY_SIZE(a));
    return 0;
}

int main() {
    int a[]={1,2,3};
    int b[]={4,5,6};
    //calc(a);
    //calc(b);
    //warning: ‘sizeof’ on array function parameter ‘a’ will return size of ‘int *’ [-Wsizeof-array-argument]
    __calc(a,ARRAY_SIZE(a));
    __calc(b,ARRAY_SIZE(b));
    return 0;
}

