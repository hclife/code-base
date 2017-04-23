//Attribute parser
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

char tag[MAXL],buf[MAXL];int pos=0;
char attrib[MAXL],value[MAXL],equalize[MAXL];
map<string,string> mapString;

void scan() {
    char c,key[MAXL],val[MAXL];
    while (1) {
	scanf("%s",attrib);
	scanf("%s",equalize);
	scanf("%s",value);
	int p=pos;strcpy(key,tag);
	for (rint i=0;c=attrib[i];++i) key[p++]=c;
	key[p]=0;

	int j=0;
	for (rint i=1;c=value[i];++i) {
	    if (c=='"') break;
	    val[j++]=c;
	}
	val[j]=0;

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
	int len=strlen(buf);
	if (buf[1]!='/') {
	    if (pos>0) tag[pos++]='.';
            int empty=0;
	    for (rint i=1;i<len;++i) {
                if (buf[i]=='>') empty=1;
		else tag[pos++]=buf[i];
            }
	    tag[pos++]='~';
            if (!empty) scan();
	    tag[--pos]=0;
	} else {
	    while (pos>0 && tag[--pos]!='.');
	    if (pos>0) tag[pos]=0;
	}

    }
    string skey,sval;
    map<string,string>::iterator itor;
    while (Q--) {
	cin>>skey;
	itor=mapString.find(skey);
	if (itor!=mapString.end())
	    cout<<itor->second<<endl;
	else cout<<"Not Found!"<<endl;
    }
    return 0;
}

