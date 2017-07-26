//count the list elements
#include <cstdio>
#include <iostream>
using namespace std;

#define MAXV(x,y)   ((x)>(y)?(x):(y))
#define rint	    register int

typedef struct list {
    struct list *next;
    int data;
} list;

int get_max(list *head) {
    if (!head) return -1;
    int next_max=get_max(head->next);
    return MAXV(head->data,next_max);
}

int get_sum(list *head) {
    if (!head) return 0;
    return head->data+get_sum(head->next);
}

struct list *list_new(int x) {
    struct list *p=new list;
    p->data=x;p->next=NULL;
    return p;
}

struct list *list_add(list *head,int x) {
    if (!head) return list_new(x);
    struct list *p=head;
    while (p->next) p=p->next;
    p->next=list_new(x);
    return head;
}

int list_count(list *head) {
    int ret=0;
    while (head) {
	++ret;
	head=head->next;
    }
    return ret;
}

struct list *list_free(list *head) {
    while (head) {
	list *next=head->next;
	delete head;
	head=next;
    }
    return NULL;
}

int main() {
    int T;cin>>T;
    for (rint t=1;t<=T;++t) {
	int N;cin>>N;
	struct list *head=NULL;
	for (rint i=1;i<=N;++i) {
	    int x;cin>>x;
	    head=list_add(head,x);
	}
	int max=get_max(head);
	int sum=get_sum(head);
	int n=list_count(head);
	double avg=double(sum)/n;
	printf("Case #%d\n",t);
	printf("max=%d,sum=%d,avg=%.2lf\n",max,sum,avg);
	head=list_free(head);
    }
    return 0;
}
