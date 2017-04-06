#include <cstdio>
#include <cassert>
#include <iostream>
using namespace std;

#define rint	    register int
#define is_valid(x) ((x)>=1 && (x)<=n)

struct list {
    int idx;
    struct list *prev;
    struct list *next;
};

struct list *list_new(int idx) {
    struct list *data=new list;
    data->prev=data->next=data;
    data->idx=idx;
    return data;
}

//return the new list node
struct list *list_add(list *tail,int idx) {
    struct list *data=list_new(idx);
    struct list *head=tail->next;
    tail->next=data;data->prev=tail;
    head->prev=data;data->next=head;
    return data;
}

//return the next list node
struct list *list_remove(list *now) {
    struct list *prev=now->prev;
    struct list *next=now->next;
    prev->next=next;next->prev=prev;
    now->prev=now->next=NULL;
    delete now;
    return next;
}

//kill one person and return the next start pos
struct list *kill(list *start,int m,int *x) {
    while (--m) start=start->next;
    *x=start->idx;
    return list_remove(start);
}

void josephus(int n,int s,int m) {
    if (n<=0 || m<=0) {
	printf("input n/m failed:n=%d,m=%d\n",n,m);
	return;
    }
    if (!is_valid(s)) {
	printf("input start failed:s=%d\n",s);
	return;
    }
    struct list *data=list_new(1);
    struct list *tail=data,*start=data;
    for (rint i=2;i<=n;++i) {
	tail=list_add(tail,i);
	if (i==s) start=tail;
    }
    int x=0;
    for (rint i=1;i<=n;++i) {
	start=kill(start,m,&x);
	cout<<x<<' ';
    }
    cout<<endl;
}

int main() {
    int T;cin>>T;
    int n,s,m;
    while (T--) {
	cin>>n>>s>>m;
	josephus(n,s,m);
    }
    return 0;
}
