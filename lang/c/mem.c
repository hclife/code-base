#include <stdio.h>
#include <string.h>

int main()
{
	int a[4]={0};int i;
	for(i=0;i<4;++i) printf("%d ",a[i]);
	putchar('\n');
	memset(a,1,4);
	//memset(a,0xFF,sizeof(a));
	printf("sizeof(a)=%lu\n",sizeof(a));
	printf("sizeof(int)=%lu\n",sizeof(int));
	printf("a[%d]=%d=0x%08x\n",0,a[0],a[0]);
	//for(int i=0;i<4;++i) printf("%d ",a[i]);
	//putchar('\n');
	return 0;
}
