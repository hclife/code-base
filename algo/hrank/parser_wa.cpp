//attribute parser
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cassert>
#include <map>
#include <string>
using namespace std;

#define MAXL	256
#define rint	register int

int pos=0;
char tag[MAXL],buf[MAXL];
char attrib[MAXL],value[MAXL];
char equalize[MAXL];
map<string,string> mapString;

void scan() {
	char c,key[MAXL],val[MAXL];
	while (1) {
		scanf("%s",attrib);
		scanf("%s",equalize);
		scanf("%s",value);
		//assert(equalize[0]=='=');
		//assert(value[0]=='"');
		int p=pos;strcpy(key,tag);
		for (rint i=0;c=attrib[i];++i) key[p++]=c;
		key[p]=0;

		int j=0;
		for (rint i=1;c=value[i];++i) {
			if (c=='"') break;
			val[j++]=c;
		}
		val[j]=0;

		//puts(key);puts(val);
		string skey(key);
		string sval(val);
		mapString.insert(map<string,string>::value_type(skey,sval));

		int vlen=strlen(value);
		if (value[vlen-1]=='>') return;
	}
}

int main() {
	int N,Q;cin>>N>>Q;
	while (N--) {
		scanf("%s",buf);
		//assert(buf[0]=='<');
		int len=strlen(buf);
		if (buf[1]!='/') {
			if (pos>0) tag[pos++]='.';
			for (rint i=1;i<len;++i)
				tag[pos++]=buf[i];
			tag[pos++]='~';
			scan();
			tag[--pos]=0;
		} else {
			while (pos>0 && tag[--pos]!='.');
			//printf("pop pos=%d\n",pos);
			if (pos>0) tag[--pos]=0;
		}

	}
	string skey,sval;
	map<string,string>::iterator itor;
	while (Q--) {
		cin>>skey;
		itor=mapString.find(skey);
		if (itor!=mapString.end())
			cout<<itor->second<<endl;
		else
			cout<<"Not Found!"<<endl;
	}
	return 0;
}
