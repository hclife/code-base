#include <stdio.h>

void quick_sort(int s[],int l,int r) {
    if (l>=r) return;
    int i=l,j=r,x=s[l];
    while (i<j) {
	while (i<j && s[j]>=x) --j;
	if (i<j) s[i++]=s[j];
	while (i<j && s[i]<=x) ++i;
	if (i<j) s[j--]=s[i];
    }
    s[i]=x;
    //quick_sort(s,l,i-1);
    //quick_sort(s,i+1,r);
}

int main() {
    int s[]={49,38,65,97,76,13,27,49};
    int len=sizeof(s)/sizeof(s[0]);
    quick_sort(s,0,len-1);
    for (int i=0;i<len;++i) printf("%d ",s[i]);
    putchar('\n');
    return 0;
}
