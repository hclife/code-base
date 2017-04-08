/* 3d version */
#include <stdio.h>

int main()
{
	int a[][3][4]={{{0,1,2,3},{4,5,6,7},{8,9,0,1}},
		{{2,3,4,5},{6,7,8,9},{0,1,2,3}}};
	int (*p)[3][4]=a;
	size_t ntabs=sizeof(a)/sizeof(a[0]);
	size_t nrows=sizeof(a[0])/sizeof(a[0][0]);
	size_t ncols=sizeof(a[0][0])/sizeof(a[0][0][0]);

	int i,j,k;
	printf("sizeof(*p)=%lu\n",sizeof(*p));
	for (i=0;i<ntabs;++i) {
		for (j=0;j<nrows;++j) {
			for (k=0;k<ncols;++k)
				printf("%d ",p[i][j][k]);
			putchar('\n');
		}
		putchar('\n');
	}
	return 0;
}
