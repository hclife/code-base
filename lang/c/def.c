#include <stdio.h>
#include <string.h>

int main()
{
	int N;scanf("%d",&N);
	int A[N];memset(A,0,sizeof(A));
	for (int i=0;i<N;++i)
		printf("%d ",A[i]);
	putchar('\n');

	return 0;
}
