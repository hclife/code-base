#include <cerrno>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

#define VERIFY   0
#define COUNTING 1

char buf[256];
int count[260];

//Hexadecimal digits check
bool is_hex(char c) {
	if (c>='0' && c<='9') return true;
	if (c>='a' && c<='f') return true;
	if (c>='A' && c<='F') return true;
	return false;
}

int to_hex(char c) {
	if (c>='0' && c<='9') return c-'0';
	if (c>='a' && c<='f') return 10+c-'a';
	if (c>='A' && c<='F') return 10+c-'A';
	return -1;
}

int main() {
	//freopen("en_test.txt","r",stdin);
	//freopen("en_read.txt","r",stdin);
	//freopen("en_write.txt","r",stdin);
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
		buf[strlen(buf)-1]=0;
		//cout<<buf;
		int num=0,start=0,len=strlen(buf);
		for (int i=0;i<len-1;++i) {
			if (buf[i]=='0' && buf[i+1]=='x') ++start;
			if (start!=2) continue;
			for (int j=i+2;j<len && is_hex(buf[j]);++j) {
				num=num*16+to_hex(buf[j]);
			}
			break;
		}
		//printf(" num=%d\n",num);
		assert(num<=256);
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

#if COUNTING
	int start=0;
	for (int lba=0;lba<8;++lba) start+=count[lba];
	printf("range data=[0,4K),sector=[0,8)\thas %d cmds.\n",start);

	for (int sec=8;sec<=256;sec<<=1) {
		printf("range data=%dK,",sec/2);
		printf("sector=%d\t\thas %d cmds.\n",sec,count[sec]);
		int total=0;
		for (int lba=sec+1;lba<sec*2;++lba)
			total+=count[lba];
		printf("range data=(%dK,%dK),",sec/2,sec);
		printf("sector=(%d,%d)\thas %d cmds.\n",sec,sec*2,total);
	}
#endif

	if (fp) fclose(fp);

	return 0;
}
