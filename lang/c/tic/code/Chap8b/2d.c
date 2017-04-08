/* 2d version */
#include <stdio.h>

int main()
{
	int a[][4]={{0,1,2,3},{4,5,6,7},{8,9,0,1}};
	int (*p)[4]=a;
	size_t nrows=sizeof(a)/sizeof(a[0]);
	size_t ncols=sizeof(a[0])/sizeof(a[0][0]);
	printf("sizeof(*p)=%lu\n",sizeof(*p));
	int i,j;
	for (i=0;i<nrows;++i) {
		for (j=0;j<ncols;++j)
			printf("%d ",p[i][j]);
		putchar('\n');
	}
	return 0;
}
