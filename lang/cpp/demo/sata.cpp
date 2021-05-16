#include <cerrno>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

#define VERIFY 1
#define is_digit(c)	((c)>='0' && (c)<='9')

char buf[256];
int count[260];

int main() {
	//freopen("ts_test.txt","r",stdin);
	//freopen("ts_read.txt","r",stdin);
	//freopen("ts_write.txt","r",stdin);
	//string file;cin>>file;
	char file[128];cin>>file;
	FILE *fp=freopen(file,"r",stdin);
	if (!fp) {
		printf("%s,errno=%d\n",strerror(errno),errno);
		return 0;
	}
	setbuf(stdout,NULL);
	memset(count,0,sizeof(count));
	while (fgets(buf,sizeof(buf),stdin)) {
		int num=0,len=strlen(buf);
		for (int i=0;i<len-2;++i)
		if (buf[i]=='s' && buf[i+1]=='c' && buf[i+2]==':') {
			for (int j=i+3;j<len && is_digit(buf[j]);++j) {
				num=num*10+buf[j]-'0';
			}
			break;
		}
		assert(num<260);
		++count[num];
	}

#if VERIFY
	int sum=0;
	bool flag=false;
	for (int i=0;i<=256;++i) {
		sum+=count[i];
		if (i<=10) printf("count[%d]=%d\n",i,count[i]);
		else if (!flag) {
			flag=true;
			printf("...\n");
		}
	}
	printf("sum=%d\n",sum);
#endif
	int start=0;
	for (int lba=0;lba<8;++lba) start+=count[lba];
	printf("range data=[0,4K),sector=[0,8) has %d cmds.\n",start);

	for (int sec=8;sec<=256;sec<<=1) {
		printf("range data=%dK,",sec/2);
		printf("sector=%d has %d cmds.\n",sec,count[sec]);
		int total=0;
		for (int lba=sec+1;lba<sec*2;++lba)
			total+=count[lba];
		printf("range data=(%dK,%dK),",sec/2,sec);
		printf("sector=(%d,%d) has %d cmds.\n",sec,sec*2,total);
	}

	if (fp) fclose(fp);

	return 0;
}
