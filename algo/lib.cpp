#ifndef __LIB_FILE__
#define __LIB_FILE__

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmalloc>
#include <climit>
#include <ctime>
#include <cassert>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <bits/stdc++.h>
using namespace std;

//#define log
#define log		printf

#define uint		unsigned int
#define uchar		unsigned char
#define ushort		unsigned short
#define ll		long long
#define ull		unsigned long long
#define rint		register int
#define rchar		register char
#define rshort		register short
#define ruint		register uint
#define ruchar		register uchar
#define rushort		register ushort

#define s8		char
#define s16		short
#define s32		int
#define s64		long long
#define u8		unsigned char
#define u16		unsigned short
#define u32		unsigned int
#define u64		unsigned long long

#define MAXZ		26
#define MAX		128
#define MAXN		MAX
#define MAXM		MAX
#define MAXP		(1e-12)
#define MAXD		1024
#define SIZE		1024
#define DIV		(1e8+7LL)
#define MOD		40096
#define INF		0x1FFFFFFF
#define LEN_TRIE	sizeof(struct trie)
#define LEN_TREE	sizeof(struct tree)
#define LEN_LIST	sizeof(struct list)
#define HASH(key)	(key%MOD)
#define MINV(x,y)	((x)<(y)?(x):(y))
#define MAXV(x,y)	((x)>(y)?(x):(y))
#define ABS(x)		((x)>=0?(x):-(x))
#define SWAP(T,x,y)	{T t=(x);(x)=(y);(y)=t;}
#define is_equal(x,y)	(ABS((x)-(y))<MAXP)
#define is_digit(c)	((c)>='0' && (c)<='9')
#define is_low_case(c)	((c)>='a' && (c)<='z')
#define is_up_case(c)	((c)>='A' && (c)<='Z')
#define is_alpha(c)	(is_low_case(c) || is_up_case(c))
#define queue_init		(head=tail=0)
#define queue_is_empty		(head==tail)
#define queue_is_full		(head==(tail+1)%SIZE)
#define en_queue_simple(x)	(queue[tail++]=(x))
#define de_queue_simple		(queue[head++])
#define stack_init		(top=0)
#define stack_is_full		(top==SIZE)
#define stack_is_empty		(!top)
#define pop_stack_simple	(stack[--top])
#define push_stack_simple(x)	(stack[top++]=(x))
#define for_each_one		for (rint i=1;i<=N;++i) \
				for (rint j=1;j<=M;++j)
#define for_each(R,C)		for (rint i=1;i<=(R);++i) \
				for (rint j=1;j<=(C);++j)


typedef struct point {
	int data;
} point;

int N,M,C;
int map[MAX][MAX]={0};

void dump(int map[MAX][MAX],const char *str) {
	printf("The dump %s:\n",str);
	for (int i=1;i<=N;++i) {
		for (int j=1;j<=M;++j) printf("%d ",map[i][j]);
		printf("\n");
	}
}

template <class T>
void dumpv(vector<T> &v,const string s) {
	cout<<s<<":";
	for (int i=0;i<v.size();++i)
		cout<<v[i]<<' ';
	cout<<endl;
}

template <class T>
void dumps(set<T> &s) {
	for (auto it=s.begin();it!=s.end();++it)
		cout<<*it<<' ';
	cout<<endl;
}

/*
----------------
Sorting
----------------
*/

void swap(int *a,int *b) {
	int t=*a;*a=*b;*b=t;
}

void swap(int x,int y) {
	x^=y;y^=x;x^=y;
}

void swap_point(struct point *x, struct point *y) {
	struct point t=*x;*x=*y;*y=t;
}

/* O(N^2) */
void bubble_sort(int s[],int l,int r) {
	for (rint i=l;i<r;++i)
	for (rint j=l;j<=r-i;++j)
	if (s[j]>s[j+1]) swap(&s[j],&s[j+1]);
}

// 0 ~ n-1
void bubble_sort(int s[],int n) {
	for (rint i=1;i<n;++i)
	for (rint j=0;j<n-i;++j)
	if (s[j]>s[j+1]) swap(&s[j],&s[j+1]);
}

/* O(N^2) */
void selection_sort(int s[],int l,int r) {
	rint i,j,min;
	for (i=l;i<r;++i) {
		for (min=i,j=i+1;j<=r;++j)
		if (s[min]>s[j]) min=j;
		if (i!=min) swap(&s[i],&s[min]);
	}
}

/* O(N^2) */
void insertion_sort(int s[],int l,int r) {
	rint i,j,key;
	for (i=l;i<=r;++i) {
		key=s[i];
		j=i-1;
		while (j>=l && s[j]>key) {
			s[j+1]=s[j];
			--j;
		}
		s[j+1]=key;
	}
}

/* O(N^2) */
void insertion_sort(int s[],int l,int r) {
	rint i,j,k;
	for (i=l+1;i<=r;++i) {
		k=s[i];
		for (j=i-1;j>=l && s[j]>key;--j) s[j+1]=s[j];
		s[j+1]=k;
	}
}


/* O(N+MAX)
 * Only used when data is small non-negative integers */
int count[MAXD+10],output[MAXN];
void counting_sort(int s[],int l,int r) {
	if (l>=r) return;
	rint i,j;
	memset(count,0,sizeof(count));
	memset(output,0,sizeof(output));
	for (i=l;i<=r;++i) count[s[i]]++;
	for (i=j=0;i<=MAX;++i)
	while (count[i]--) output[++j]=i;
}

void shell_sort(int s[],int l,int r) {
}


//----------min heap-------------------//
void min_heap_fix_up(int s[],int i) {
	// i:child,j:father
	rint j=(i-1)>>1,t=s[i];
	for (;i && j>=0;i=j,j=(i-1)>>1) {
		if (s[j]<=t) break;
		s[i]=s[j];
	}
	s[i]=t;
}

void min_heap_add(int s[],int n,int x) {
	s[n]=x;
	min_heap_fix_up(s,n);
}

void min_heap_fix_down(int s[],int i,int n) {
	// i:father,j:child
	rint j=(i<<1)+1,t=s[i];
	for (;j<n;i=j,j=(i<<1)+1) {
		if (j+1<n && s[j+1]<s[j]) ++j;
		if (s[j]>=t) break;
		s[i]=s[j];
	}
	s[i]=t;
}

void min_heap_del(int s[],int n) {
	swap(&s[0],&s[n-1]);
	min_heap_fix_down(s,0,n-1);
}

void make_min_heap(int s[],int n) {
	for (rint i=(n>>1)-1;i>=0;--i)
		min_heap_fix_down(s,i,n);
}

void make_descending(int s[],int n) {
	for (rint i=n-1;i>=1;--i) {
		swap(&s[i],&s[0]);
		min_heap_fix_down(s,0,i);
	}
}

//----------max heap-------------------//
void max_heap_fix_up(int s[],int i) {
	// i:child,j:father
	rint j=(i-1)>>1,t=s[i];
	for (;i && j>=0;i=j,j=(i-1)>>1) {
		if (s[j]>=t) break;
		s[i]=s[j];
	}
	s[i]=t;
}

void max_heap_add(int s[],int n,int x) {
	s[n]=x;
	max_heap_fix_up(s,n);
}

void max_heap_fix_down(int s[],int i,int n) {
	// i:father,j:child
	rint j=(i<<1)+1,t=s[i];
	for (;j<n;i=j,j=(i<<1)+1) {
		if (j+1<n && s[j+1]>s[j]) ++j;
		if (s[j]<=t) break;
		s[i]=s[j];
	}
	s[i]=t;
}

void max_heap_del(int s[],int n) {
	swap(&s[0],&s[n-1]);
	max_heap_fix_down(s,0,n-1);
}

void make_max_heap(int s[],int n) {
	for (rint i=(n>>1)-1;i>=0;--i)
		max_heap_fix_down(s,i,n);
}

void make_ascending(int s[],int n) {
	for (rint i=n-1;i>=1;--i) {
		swap(&s[i],&s[0]);
		max_heap_fix_down(s,0,i);
	}
}

/* O(NlogN): descending order 
 * NOTE: data index range is 0~n-1 */
void min_heap_sort(int s[],int n) {
	make_min_heap(s,n);
	make_descending(s,n);
}

/* O(NlogN): ascending order
 * NOTE: data index range is 0~n-1 */
void max_heap_sort(int s[],int n) {
	make_max_heap(s,n);
	make_ascending(s,n);
}

/* O(NlogN) ~ O(N^2) */
void quick_sort(int s[],int l,int r) {
	if (l>=r) return;
	rint i=l,j=r,x=s[l];
	while (i<j) {
		while (i<j && s[j]>=x) --j;
		if (i<j) s[i++]=s[j];
		while (i<j && s[i]<=x) ++i;
		if (i<j) s[j--]=s[i];
	}
	s[i]=x;
	quick_sort(s,l,i-1);
	quick_sort(s,i+1,r);
}

void merge_union(int s[],int l,int m,int r,int t[]) {
	rint i=l,j=m+1,k=l;
	while (i<=m && j<=r) {
		if (s[i]<=s[j]) t[k++]=s[i++];
		else t[k++]=s[j++];
	}
	while (i<=m) t[k++]=s[i++];
	while (j<=r) t[k++]=s[j++];
	for (i=l;i<=r;++i) s[i]=t[i];
}

/* O(NlogN) */
void merge_sort(int s[],int l,int r,int t[]) {
	if (l>=r) return;
	int m=l+(r-l)>>1; /* prevent overflow */
	merge_sort(s,l,m,t);
	merge_sort(s,m+1,r,t);
	merge_union(s,l,m,r,t);
}


/*
----------------
Searching
----------------
*/

/* O(logN): recursive */
int bsearch_recurse(int s[],int l,int r,int key) {
	if (l>r) return -1;
	int m=l+(r-l)>>1;
	if (key>s[m]) return bsearch_recurse(s,m+1,r,key);
	if (key<s[m]) return bsearch_recurse(s,l,m-1,key);
	return m;
}

/* O(logN): loop */
int bsearch_loop(int s[],int l,int r,int key) {
	if (l>r) return -1;
	while (l<=r) {
		int m=l+(r-l)>>1;
		if (key>s[m]) l=m+1;
		else if (key<s[m]) r=m-1;
		else return m;
	}
	return -1;
}

int my_lower_bound(int *s,int size,int key) {
	int pos=0,first=0,last=size-1;
	while (first<last) {
		int mid=(first+last)<<1;
		if (key>s[mid]) pos=first=mid+1;
		else pos=last=mid;
	}
	return pos;
}

int my_upper_bound(int *s,int size,int key) {
	int pos=0,first=0,last=size-1;
	while (first<last) {
		int mid=(first+last)<<1;
		if (key<s[mid]) pos=last=mid;
		else pos=first=mid+1;
	}
	return pos;
}

int stl_lower_bound(int *s,int size,int key) {
	int first=0,len=size;
	while (len>0) {
		int half=len>>1;
		int mid=first+half;
		if (key>s[mid]) {
			first=mid+1;
			len=len-half-1;
		} else {
			len=half;
		}
	}
	return first;
}

int stl_upper_bound(int *s,int size,int key) {
	int first=0,len=size-1;
	while (len>0) {
		int half=len>>1;
		int mid=first+half;
		if (key<s[mid]) {
			len=half;
		} else {
			first=mid+1;
			len=len-half-1;
		}
	}
	return first;
}

bool stl_binary_search(int *s,int size,int key) {
	int first=stl_lower_bound(s,size,key);
	return (first<size && s[first]==key);
}



/*
--------------------
Queue
--------------------
*/
int head,tail;
point queue[SIZE];

void en_queue(point p) {
	if (queue_is_full) return;
	queue[tail]=p;
	tail=(tail+1)%SIZE;
}

point de_queue() {
	point p={0};
	if (queue_is_empty) return p;
	p=queue[head];
	head=(head+1)%SIZE;
	return p;
}

/*
--------------------
Stack
--------------------
*/
int top;
point stack[SIZE];

void push_stack(point p) {
	if (stack_is_full) return;
	stack[top++]=p;
}

point pop_stack() {
	point p={0};
	if (stack_is_empty) return p;
	p=stack[--top];
	return p;
}

/*
-------------------------------------
Single Link List
-------------------------------------
*/

/* Iterate over a single list */
#define slist_for_each(pos,head) \
	for (pos=(head)->next;pos;pos=pos->next)

typedef struct single_list {
	struct single_list *next;
	int data;
} slist;

void slist_init(slist *list) {
	list->next=NULL;
}

int slist_is_empty(const slist *head) {
	return head->next==NULL;
}

slist *slist_search(const slist *head,int key) {
	slist *p;
	slist_for_each(p,head)
	if (key==p->data) return p;
	return NULL;
}

void slist_add_tail(slist *head, slist *node) {
}

void slist_del_free(slist *entry) {
}

//find the middle node of a single list
slist *slist_find_mid(slist *head) {
    slist *fast=head,*slow=head;
    while (fast && fast->next) {
	fast=fast->next->next;
	slow=slow->next;
    }
    return slow;
}

//floyd:tortoise and hare algorithm
//check if loop exist in single list
//If exist then return meeting point
slist *slist_check_loop(slist *head) {
    slist *fast=head,*slow=head;
    while (fast && fast->next) {
	fast=fast->next->next;
	slow=slow->next;
	if (fast==slow) return fast;
    }
    return NULL;
}

//search for loop length of a single list
size_t slist_search_loop_len(slist *head) {
    slist *fast=slist_check_loop(head);
    if (!fast) return 0;
    size_t count=1;
    for (slist *p=fast->next;p!=fast;p=p->next) ++count;
    return count;
}

//search for loop entry of a single list
slist *slist_search_loop_start(slist *head) {
    slist *fast=slist_check_loop(head);
    if (!fast) return NULL;
    while (head!=fast) {
	head=head->next;
	fast=fast->next;
    }
    return fast;
}

slist *slist_reverse(slist *head) {
    slist *prev=NULL;
    while (head) {
	slist *next=head->next;
	head->next=prev;
	prev=head;
	head=next;
    }
    return prev;
}

//check if two non-loop slist overlap with each other
slist *slist_check_cross(slist *head1,slist *head2) {
    slist *pos=head1;
    while (pos && pos->next) pos=pos->next;
    if (pos) pos->next=head1;
    return slist_check_loop(head2);
}



/*
-------------------------------------
Double Link List: from Linux kernel
-------------------------------------
*/

/* Iterate over a list */
#define list_for_each_forwards(pos,head) \
	for (pos=(head)->next;pos!=(head);pos=pos->next)
#define list_for_each_backwards(pos,head) \
	for (pos=(head)->prev;pos!=(head);pos=pos->prev)

typedef struct double_list {
	struct double_list *next,*prev;
	int data;
} dlist;

void dlist_init_head(dlist *list) {
	list->prev=list;
	list->next=list;
}

/* Search a list for data key */
dlist *dlist_search(const dlist *head,int key) {
	dlist *p;
	list_for_each_forwards(p,head) {
		if (key==p->data) return p;
	}
	return NULL;
}

/* Test whether a list is empty */
int dlist_is_empty(const dlist *head) {
	return head->next==head;
}

/* Test whether a list is empty and not being modified */
int dlist_is_empty_careful(const dlist *head) {
	dlist *next=head->next;
	return (next==head) && (next==head->prev);
}

/* Test whether @list is the last entry in list @head */
int dlist_is_last(const dlist *list,const dlist *head) {
	return list->next==head;
}

/* Test whether a list has just only one entry */
int dlist_is_singular(const dlist *head) {
	return !dlist_is_empty(head) && (head->next==head->prev);
}

/* Insert a new entry between two known consecutive entries.
 * This is only for internal list manipulation where we know
 * the prev/next entries already!
 */
void __list_add(dlist *now,dlist *prev,dlist *next) {
	next->prev=now;
	now->next=next;
	now->prev=prev;
	prev->next=now;
}

/* Insert a new entry after the specified head.
 * This is good for implementing stacks.
 */
void dlist_add_head(dlist *now,dlist *head) {
	__list_add(now,head,head->next);
}

/* Insert a new entry before the specified head.
 * This is useful for implementing queues.
 */
void dlist_add_tail(dlist *now,dlist *head) {
	__list_add(now,head->prev,head);
}

/* Delete a list entry by making the prev/next entries point
 * to each other.
 */
void __list_del(dlist *prev,dlist *next) {
	next->prev=prev;
	prev->next=next;
}

/* Delete @entry from list, and the entry is in an undefined state. */
void __list_del_entry(dlist *entry) {
	__list_del(entry->prev,entry->next);
}

/* Delete @entry from list and reinitialize it. */
void list_del_init(dlist *entry) {
	__list_del_entry(entry);
	list_init_head(entry);
}

/* Delete @entry from list and free the space of entry. */
void list_del_free(dlist *entry) {
	__list_del(entry->prev,entry->next);
	entry->next=NULL;
	entry->prev=NULL;
	free(entry);
}

/* Replace old entry by new one. */
void list_replace(dlist *old,dlist *now) {
	now->next=old->next;
	now->next->prev=now;
	now->prev=old->prev;
	now->prev->next=now;
}


/*
------------------------
Binary Search Tree (BST)
------------------------
*/
typedef struct tree {
	int data,freq;
	struct tree *lson;
	struct tree *rson;
} tree;

tree *tree_search(tree *root,int key) {
	if (!root) return NULL;
	if (key<root->data) return tree_search(root->lson,key);
	if (key>root->data) return tree_search(root->rson,key);
	return root;
}	

void tree_insert(tree *root, tree *father,int key) {
	if (!root) {
		root=(tree *)malloc(LEN_TREE);
		root->data=key;
		root->freq=0;
		root->lson=root->rson=NULL;
		if (!father) return;
		if (key<father->data) father->lson=root;
		if (key>father->data) father->rson=root;
		return;
	}
	if (key<root->data) return tree_insert(root->lson,root,key);
	if (key>root->data) return tree_insert(root->rson,root,key);
	root->freq++;	
}

tree *tree_create(int s[],int n) {
	tree *root=NULL;
	for (rint i=1;i<=n;++i) tree_insert(root,root,s[i]);
	return root;	
}

void tree_in_visit(tree *root) {
	if (!root) return;
	if (root->lson) tree_in_visit(root->lson);
	printf("%d:%d ",root->data,root->freq);
	if (root->rson) tree_in_visit(root->rson);
}

void tree_free(tree *root)
{
}

/*
---------------------
BST traversal
---------------------
*/
preOrder(BinaryTree *t) { //DFS
	if (!t->empty()) {
		process(t);
		preOrder(t->left);
		preOrder(t->right);
	}
}

inOrder(BinaryTree *t) { //Ascending BST
	if (!t->empty()) {
		inOrder(t->left);
		process(t);
		inOrder(t->right);
	}
}

postOrder(BinaryTree *t) {
	if (!t->empty()) {
		postOrder(t->left);
		postOrder(t->right);
		process(t);
	}
}

levelOrder(BinaryTree *t) { //BFS
	if (!t->empty()) {
		queue.enqueue(t);
		while (!queue.empty()) {
			BinaryTree tree=queue.dequeue();
			process(tree);
			if (tree->left) queue.enqueue(tree->left);
			if (tree->right) queue.enqueue(tree->right);
		}
	}
}


/*
----------------
Graph
----------------
*/

typedef struct list {
	struct list *next;
	int v,cost;
} list;


typedef struct edge {
	int fm,to;
	int cost;
} edge;


/* gcount[i]=x:		There are x lines from ith vertex.
 * glist[i][j]=k:	The jth line from ith vertext is the kth edge list.
 * dist[i]=x:		The shortest distance start from S to ith vertex.
 * prev[i]=x:		The previous vertex of ith vertext is the xth vertex.
 * line[i]=x:		The edge information of the ith line.
 * map[i]=x:		The list information of the ith vertex.
 * in_count[i]=x:	The ith vertext was put into queue for x times.
 */
int prev[MAXN],dist[MAXN],in_count[MAXN];
int gcount[MAXN],glist[MAXN][MAXN];
edge line[MAXM];list *map[MAXN];

void dump_list(int x, list *head) {
	printf("%d: ",x);
	for (list *p=head;p;p=p->next)
		printf("%d:%d ",p->v,cost);
	printf("\n");
}

void dump_map() {
	for (rint i=1;i<=N;++i)
	if (map[i]) dump_list(i,map[i]);
}

void write_to_map(int x,int y,int c) {
	if (!map[x]) {
		map[x]=(list *)malloc(LEN_LIST);
		map[x]->v=y;map[x]->cost=c;
		map[x]->next=NULL;
		return;
	}

	list *p;
	for (p=map[x];p->next;p=p->next);
	p->next=(list *)malloc(LEN_LIST);
	p=p->next;p->v=y;p->cost=c;
	p->next=NULL;
}

/* create graph link list for lines */
void graph_create_list() {
	int fm,to,cost;
	for (rint i=1;i<=N;++i) map[i]=NULL;
	for (rint i=1;i<=M;++i) {
		scanf("%d %d %d",&fm,&to,&cost);
		write_to_map(fm,to,cost);
		write_to_map(to,fm,cost);
	}
}

/* create graph array list for lines */
void graph_create_glist() {
	int fm,to,cost;
	memset(gcount,0,sizeof(gcount));
	memset(glist,0,sizeof(glist));
	for (rint i=1;i<=M;++i) {
		scanf("%d %d %d",&fm,&to,&cost);
		line[i].fm=fm;line[i].to=to;
		line[i].cost=cost;
		glist[fm][++gcount[fm]]=i;
	}
}

int graph_bfs() {
	point in,out;queue_init();
	in.data=some_initial_data;
	en_queue(in);
	while (!queue_is_empty) {
		out=de_queue();
		if (out.data==final_state) return out.data;
		for (spread_to_new_nodes) {
			if (valid(new_nodes)) {
				in.data=get_new_data(out.data);
				en_queue(in);
			}
		}
	}
	return -1;
}

void graph_dfs(int x) {
	++C;vis[x]=1;
	for (rint i=1;i<=N;++i) {
		if (vis[i]) continue;
		if (map[x][i]>0) graph_dfs(i);
	}
}

int main() {
	C=0;memset(vis,0,sizeof(vis));graph_dfs(1);
	if (C==N) printf("The graph is connected.\n");
	else printf("The graph is disjoint.\n");
	return 0;
}

// Start from v to get the min weight sum and MST of a graph
// MST:O(N^2) useful for dense graph
int prim(int v,int low[],int prev[]) {
	int ret=0;
	memset(vis,0,sizeof(vis));
	memset(low,0,sizeof(low));
	memset(prev,0,sizeof(prev));
	vis[v]=1;low[v]=prev[v]=0;
	for (rint i=1;i<=N;++i) {
		if (vis[i]) continue;
		low[i]=map[v][i];
		prev[i]=v;
	}
	for (rint i=1;i<N;++i) {
		// find the min weight node and the position
		rint min=-1,pos=-1;
		for (rint j=1;j<=N;++j) {
			if (vis[j] || low[j]<0) continue;
			if (min<0 || min>low[j]) min=low[pos=j];
		}
		ret+=min;vis[pos]=1;
		// update the low weight list with new node
		for (rint j=1;j<=N;++j) {
			if (vis[j] || map[pos][j]==-1) continue;
			if (low[j]<0 || low[j]>map[pos][j]) {
				low[j]=map[pos][j];
				prev[j]=pos;
			}
		}
	}
	return ret;
}

#define CMP(x,y)	(data[x].cost-data[y].cost)
void quick_sort_idx(int s[],int l,int r) {
	if (l>=r) return;
	int i=l,j=r,x=s[l];
	while (i<j) {
		while (i<j && CMP(s[j],x)>=0) --j;
		if (i<j) s[i++]=s[j];
		while (i<j && CMP(s[i],x)<=0) ++i;
		if (i<j) s[j--]=s[i];
	}
	s[i]=x;
	quick_sort_idx(s,l,i-1);
	quick_sort_idx(s,i+1,r);
}

int find(int x) {
	if (x==father[x]) return x;
	return father[x]=find(father[x]);
}

void unions(int x,int y) {
	int a=find(x);
	int b=find(y);
	if (a!=b) father[x]=y;
}

int father[MAXM],midx[MAXM];
struct edge data[MAXM];

// MST:O(MlogM+M) useful for loose graph
int kruskal() {
	for (int i=1;i<=N;++i) father[i]=i;
	for (int i=1;i<=M;++i) midx[i]=i;
	quick_sort_idx(midx,1,M); //sort edge index
	int count=0,ret=0;
	for (int i=1;i<=M;++i) {
		int e=midx[i];
		int x=find(data[e].fm);
		int y=find(data[e].to);
		if (x!=y) {
			father[x]=y;++count;
			ret+=data[e].cost;
		}
	}
	return count<N-1?0:ret;
}

/* Start from v to get the min distance to each nodes of a graph.
 * This is only useful for processing non-negative edge values. */
void dijkstra(int v,int dist[MAXN],int prev[MAXN]) {
	memset(vis,0,sizeof(vis));
	memset(dist,0,sizeof(dist));
	memset(prev,0,sizeof(prev));
	for (rint i=1;i<=N;++i) dist[i]=map[v][i];
	vis[v]=1;dist[v]=0; 
	for (rint i=1;i<N;++i) {
		/* find the point with the shortest path from v */
		int min=-1,pos=-1;
		for (rint j=1;j<=N;++j) {
			if (vis[j]) continue;
			if (min<0 || min>dist[j]) min=dist[pos=j];
		}
		vis[pos]=1;
		/* update the dist list with new node */
		for (rint j=1;j<=N;++j) {
			if (vis[j] || map[pos][j]==-1) continue;
			int new_dist=dist[pos]+map[pos][j];
			if (dist[j]>new_dist) {
				dist[j]=new_dist;
				prev[j]=pos;
			}
		}
	}
}

/* Get the min distance from each nodes to each nodes of a graph.
 * This is useful for processing non-negative edge values. */
void floyd(int path[MAX][MAX]) {
	memset(path,0,sizeof(path));
	for (rint k=1;k<=N;++k)
	for (rint i=1;i<=N;++i)
	for (rint j=1;j<=N;++j) {
		int val=map[i][k]+map[k][j];
		if (map[i][j]>val) {
			map[i][j]=val;
			path[i][j]=k;
		}
	}
}


/* Start from v to get the min distance to each nodes of a graph.
 * This is useful with negative edge values. Time Complexity: O(MN)
 * @ret: 1:There is negative cycle 0:There isnot neg cycle.*/
int bellman_ford(int v,int dist[MAXN],int prev[MAXN]) {
	memset(dist,0,sizeof(dist));
	memset(prev,0,sizeof(prev));
	for (rint i=1;i<=N;++i) dist[i]=INF;
	dist[v]=0;
	for (rint i=1;i<N;++i)
	for (rint j=1;j<=M;++j) {
		int val=dist[line[j].fm]+line[j].cost;
		if (dist[line[j].to]>val) {
			dist[line[j].to]=val;
			prev[line[j].to]=line[j].fm;
		}
	}
	for (rint i=1;i<=M;++i) {
		int val=dist[line[j].fm]+line[j].cost;
		if (dist[line[i].to]>val) return 1;
	}
	return 0;
}

/* The bfs queue optimized version of bellman-ford. O(KM) while K<=2 */
int spfa_bfs(int x) {
	struct point in,out;queue_init;
	vis[in.v=x]=in_count[x]=1;en_queue(in);
	while (!queue_is_empty) {
		out=de_queue();vis[x=out.v]=0;
		for (int j=1;j<=gcount[x];++j) {
			int k=glist[x][j];
			int to=line[k].to;
			int cost=line[k].cost;
			int val=dist[x]+cost;
			if (dist[to]>val) {
				dist[to]=val;
				if (vis[to]) continue;
				if (++in_count[to]>N) return 1;
				vis[in.v=to]=1;en_queue(in);
			}
		}
	}
	return 0;
}

/* The dfs optimized version of bellman-ford to search for negative loops
 * more quickly, but may need more optimization for it. */
int spfa_dfs(int x) {
	vis[x]=1;
	for (int j=1;j<=gcount[x];++j) {
		int k=glist[x][j];
		int to=line[k].to;
		int cost=line[k].cost;
		int val=dist[x]+cost;
		if (dist[to]>val) {
			dist[to]=val;
			if (vis[to] || spfa_dfs(to)) return 1;
		}
	}
	vis[x]=0;
	return 0;
}

/* Get the strongly connected components of directed graph */
int time=0,vis[MAX],low[MAX],dfn[MAX];
void tarjan(int v) {
	dfn[v]=low[v]=++time;
	vis[v]=1;stack[top++]=v;
	for (slist *p=map[v];p;p=p->next) {
		if (!dfn[p->v]) {
			tarjan(p->v);
			low[v]=MINV(low[v],low[p->v]);
		} else if (vis[p->v]) {
			low[v]=MINV(low[v],dfn[p->v]);
		}
	}
	if (dfn[v]==low[v]) {
		while (1) {
			int x=stack[--top];vis[x]=0;
			if (dfn[x]==low[x]) break;
		}
	}
}

int main() {
	time=top=0;
	memset(vis,0,sizeof(vis));
	memset(low,0,sizeof(low));
	memset(dfn,0,sizeof(dfn));
	for (rint i=1;i<=N;++i)
	if (!dfn[i]) tarjan(i);
	return 0;
}

/* match[j]=x: The jth gift is owned by person x. */
int dfs(int x) {
	for (rint j=1;j<=M;++j)
	if (map[x][j] && !vis[j]) {
		vis[j]=1;
		if (match[j]==-1 || dfs(match[j])) {
			match[j]=x;
			return 1;
		}
	}
	return 0;
}

int hungary() {
	uint ans=0;
	for (rint i=1;i<=N;++i) {
		for (rint j=1;j<=M;++j) vis[j]=0;
		if (dfs(i)) ++ans;
	}
	return ans;
}

int main() {
	int vis[MAXM],match[MAXM];
	memset(match,-1,sizeof(match));
	memset(map,0,sizeof(map));
	Ans=hunagry();
	return 0;
}

/* Union-Find */
typedef struct node {
	int num,father;
	int sum,ans,flag;
} node;
node tree[MAXN];

int find(int p) {
	if (p!=tree[p].father && tree[tree[p].father].flag)
		tree[p].father=find(tree[p].father);
	return tree[p].father;
}

int union_find(int r) {
	rint i,j,idx;
	int fm,to,cost,son_ans,father;
	double v,maxv=0.0f;
	for (i=1;i<=N;++i) {
		scanf("%d",&cost);
		tree[i].ans=tree[i].sum=cost;
		tree[i].num=1;
	}
	for (i=1;i<N;++i) {
		scanf("%d %d",&fm,&to);
		tree[to].father=fm;
	}
	tree[r].father=r;
	for (i=1;i<N;++i) {
		for (maxv=0.0f,j=1;j<=N;++j) {
			if (j==r || tree[j].flag) continue;
			v=(double)tree[j].sum/(double)tree[j].num;
			if (maxv<v) {maxv=v;idx=j;}
		}
		tree[idx].flag=1;father=find(idx);
		son_ans=tree[idx].ans+tree[idx].sum*tree[father].num;
		tree[father].ans+=son_ans;
		tree[father].sum+=tree[idx].sum;
		tree[father].num+=tree[idx].num;
	}
	return tree[r].ans;
}

void top_sort()
{
}

/* Check if there exist any cycle in map.
 * Caution: This will modify the map data.
 */
int has_cycle(int in[MAX],int out[MAX]) {
	rint i,zin_idx,zout_idx;
	while (1) {
		/* find a zero in-degree point */
		zin_idx=0;
		for (i=1;i<=N;++i)
		if (!in[i] && out[i]) {
			zin_idx=i;
			break;
		}
		if (zin_idx) {
			for (i=1;i<=N;++i)
			if (map[zin_idx][i]) {
				--in[i];
				--map[zin_idx][i];
			}
			out[zin_idx]=0;
		}

		/* find a zero out-degree point */
		zout_idx=0;
		for (i=1;i<=N;++i)
		if (!out[i] && in[i]) {
			zout_idx=i;
			break;
		}
		if (zout_idx) {
			for (i=1;i<=N;++i)
			if (map[i][zout_idx]) {
				--out[i];
				--map[i][zout_idx];
			}
			in[zout_idx]=0;
		}
		if (!zin_idx && !zout_idx) break;
	}
	for (i=1;i<=N;++i)
	if (in[i] && out[i]) return 1;

	return 0;
}

/*
----------------
String
----------------
*/

class String {
public:
	String(const char *str=NULL);
	String(const String &s);
	~String();
	String &operator=(const String &s);
private:
	char *m_data;
};

String::String(const char *str) {
	if (!str) {
		m_data=new char[1];
		*m_data='\0';
	} else {
		int len=strlen(str);
		m_data=new char[len+1];
		if (m_data) strcpy(m_data,str);
	}
}

String::~String() {
	delete [] m_data;
	m_data=nullptr;
}

String::String(const String &s) {
	int len=strlen(s.m_data);
	m_data=new char[len+1];
	if (m_data) strcpy(m_data,s.m_data);
}

String &String::operator=(const String &s) {
	if (this==&s) return *this;
	delete [] m_data;
	int len=strlen(s.m_data);
	m_data=new char[len+1];
	if (m_data) strcpy(m_data,s.m_data);
	return *this;
}

string itos(int x) {
	stringstream ss;ss<<x;
	string s;ss>>s;
	return s;
}

int str_cmp(const char *s,const char *t) {
	for (rint i=0;s[i] || t[i];++i)
	if (s[i]!=t[i]) return s[i]-t[i];
	return 0;
}

int str_cmpn(const char *s,const char *t,uint n) {
	for (rint i=0;i<n;++i)
	if (s[i]!=t[i]) return s[i]-t[i];
	return 0;
}

char *str_copy(char *s,const char *t) {
	char *p=s;
	while (*s++=*t++);
	return p;
}

int str_len(const char *s) {
	for (rint i=0;s[i];++i);
	return i;
}

void mem_set(int *s,int v,uint n) {
	//for (rint i=0;i<n;++i) s[i]=v;
	while (n--) *s++=v;
}

void mem_set(void *s,int v,size_t n) {
	char *sp=(char *)s;
	while (n--) *sp=v;
}

void mem_copy(int *s,int *t,uint n) {
	//for (rint i=0;i<n;++i) s[i]=t[i];
	while (n--) *s++=*t++;
}

void mem_copy(void *t,const void *s,size_t n) {
	char *tp=(char *)t;
	const char *sp=(const char *)s;
	while (n--) *tp++=*sp++;
}

int mem_cmpn(int *s,int *t,uint n) {
	for (rint i=0;i<n;++i)
	if (s[i]!=t[i]) return s[i]-t[i];
	return 0;
}

/* String Pattern Matching: Sunday/KMP */
int sunday(char s[],char t[]) {
}

int next[MAXM];
void make_next(char s[]) {
	next[0]=0;
	for (rint i=1,j=0;i<M;++i) {
		while (j>0 && s[i]!=s[j]) j=next[j-1];
		if (s[i]==s[j]) ++j;next[i]=j;
	}
}

/* find s in t */
int kmp(char s[],char t[]) {
	int M=strlen(s),N=strlen(t);make_next(s);
	for (rint i=0,j=0;i<N && j<M;++i) {
		while (j>0 && t[i]!=s[j]) j=next[j-1];
		if (t[i]==s[j]) ++j; if (j>=M) return 1;
	}
	return 0;
}

/* Trie Structure */
typedef struct trie {
	struct trie *next[MAXZ];
	int data;
} trie;

trie *trie_create() {
	trie *t=new trie;
	//trie *t=(trie *)malloc(LEN_TRIE);
	if (!t) return NULL;
	memset(t,0,LEN_TRIE);t->data=0;
	for (rint i=0;i<MAXZ;++i) t->next[i]=NULL;
	return t;
}

void trie_insert(trie *root,const char *s,int data) {
	rint i,c;trie *t;
	if (!root || !s[0]) return;
	for (i=0;c=s[i];++i,root=t)
	if (!(t=root->next[c-'a']))
		t=root->next[c-'a']=trie_create();
	if (!root->data) root->data=data;
}

void trie_search(trie *root,const char *s) {
	if (!root || !s[0]) return;
	rint i,c;trie *t;
	for (i=0;c=s[i];++i,root=t)
	if (!(t=root->next[c-'a'])) break;
	if (c) printf("%s\tis not in trie\n",s);
	else printf("%s\tis in trie:%d\n",s,root->data);
	return c?NULL:root;
}

void trie_delete(trie *root) {
	rint i;trie *t;
	if (!root) return;
	for (i=0;i<MAXZ;++i)
	if (t=root->next[i]) trie_delete(t);
	delete root;
	//if (root) free(root);
}

/* AC Automation */
void ac_auto()
{
}




/*
----------------
Geometry
----------------
*/

struct point {
	int x,y;
};

struct point data[MAXN],stack[MAXN];

/* O(N): Get the convex hull from a set of points
 * 	 and return the number of points in stack.
 * 	 The data index range start from 0 ~ N-1.
 */
int graham_scan() {
	int max=0;
	for (rint i=1;i<N;++i) {
		if (data[max].y==data[i].y && data[max].x>data[i].x) max=i;
		else if (data[max].y>data[i].y) max=i;
	}
	swap_point(&data[0],&data[max]);
	for (rint i=1;i<N-1;++i) {
		int low=i;
		for (rint j=i+1;j<N;++j) {
			int cos=cross_product(data[j],data[low],data[0]);
			int dot=sspot_product(data[j],data[low],data[0]);
			if (cos>0 || (cos==0 && dot<0)) low=j;
		}
		swap_point(&data[i],&data[low]);
	}
	int top=2;
	for (int i=0;i<=top;++i) stack[i]=data[i];
	for (rint i=3;i<N;++i) {
		while (1) {
			int cos=cross_product(data[i],stack[top],stack[top-1]);
			if (cos<0 || !--top) break;
		}
		stack[++top]=data[i];
	}
	return top+1;
}


/*
----------------
Math
----------------
*/

#if 0
x*(2^n) -> x<<n
x/(2^n) -> x>>n
x%2     -> x&1
x%(2^n) -> x&((1<<n)-1)
#endif

struct point {
	int x,y;
};

#define dist_product(a,b)			\
	(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)
#define sspot_product(a,b,c)			\
	((b.x-a.x)*(c.x-a.x)+(b.y-a.y)*(c.y-a.y))
#define cross_product(a,b,c)			\
	((a.x-c.x)*(b.y-a.y)-(b.x-a.x)*(a.y-c.y))

/* Get the square of distance between A and B */
int distance(struct point a, struct point b) {
	int dx=a.x-b.x;
	int dy=a.y-b.y;
	return dx*dx+dy*dy;
}

/* Euclid algo to get the greatest common divisor of two numbers */
int gcd(int x,int y) {
	if (!y) return x;
	return gcd(y,x%y);
}

/* O(N): Get the maximum continuous partial sum */
ll kadane() {
	ll sum=0LL,Ans=-INF;
	for (rint i=1;i<=N;++i) {
		sum+=data[i];
		sum=MAXV(sum,data[i]);
		Ans=MAXV(Ans,sum);
	}
	return Ans;
}

/* count how many trailing zeros of n! */
uint tzeros(uint n) {
	uint r=0;
	while (n/5) {
		r+=n/5;
		n/=5;
	}
	return r;
}

/* count how many number of 1s of a uint */
uint hakmem(uint x) {
	uint n=(x>>1)&033333333333;x-=n;
	n=(n>>1)&033333333333;x-=n;
	x=(x+(x>>3))&030707070707;
	return x%63;
}

// count how many number of 1s
uint num_of_ones(uint x) {
	uint n=0;
	while (x) {
		++n;
		x=x&(x-1);
	}
	return n;
}

bool is_little_endian() {
	int x=1;
	char *p=(char*)&x;
	return (*p)?true:false;
}

bool is_little_endian1() {
	union {
		int a;
		char b;
	} u;
	u.a=1;
	return u.b==1;
}


/* power(x^n): O(logN) */
ll power(int x,int n) {
	if (n<=0) return 1LL;
	if (n==1) return x;
	if (n==2) return x*x;
	if (n&1) return x*power(x,n-1);
	ll out=power(x,n>>1);
	return out*out;	
}

/* A <- A x B */
void matrix_multiply(ll A[MAXN][MAXN],ll B[MAXN][MAXN]) {
	ll value,O[MAXN][MAXN];
	memset(O,0LL,sizeof(O));
	for (rint k=1;k<=N;++k)
	for (rint i=1;i<=N;++i) {
		if (!A[i][k]) continue;
		for (rint j=1;j<=N;++j) {
			if (!B[k][j]) continue;
			value=(A[i][k]*B[k][j])%DIV;
			O[i][j]+=value;
			O[i][j]%=DIV;
		}
	}
	memcpy(A,O,sizeof(O));
}

int get_digits(int s[],ll n) {
	int i=0,d;
	while (n) {
		d=n%10;
		s[++i]=d;
		n/=10;
	}
	return i;
}

ll output_digits(int s[],int len) {
	ll v=0; rint i,j;
	for (j=len-1;!s[j];j--);
	for (i=j;i>=0;i--) v=v*10+s[i];
	return v;
}

#define MAXO	(2*MAX)
ll big_number_multiply(ll A,ll B) {
	ll V;rint i,j,k,lena,lenb;
	int a[MAX],b[MAX],c[MAXO];
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	lena=get_digits(a,A);
	lenb=get_digits(b,B);
	for (i=0;i<lena;++i)
	for (j=0;j<lenb;++j)
		c[i+j]+=(a[i]*b[j]);
	for (i=0;i<MAXO;++i) {
		c[i+1]+=c[i]/10;
		c[i]%=10;
	}
	/* might overflow */
	V=output_digits(c,MAXO);
	return V;
}

int is_prime0(uint x) {
	if (x<2 || (x&1)==0) return 0;
	if (x==2 || x==3) return 1;
	for (rint i=3;i*i<=x;i+=2)
	if (x%i==0) return 0;
	return 1;
}

int is_prime1(uint x) {
	if (x==2 || x==3 || x==5) return 1;
	if (x<2 || (x&1)==0) return 0;
	if (x%6!=1 && x%6!=5) return 0;
	for (rint i=5;i*i<=x;i+=6)
	if (x%i==0 || x%(i+2)==0) return 0;
	return 1;
}

// check if x is 2^n
int is_twos_multiply(uint x) {
	return (x&(x-1))==0;
}

double square_root(double x) {
	double v,val,_val,left=0.0f,right=x;
	v=val=_val=-1.0f;
	if (x<0.0f) return -1.0f;
	if (!x) return 0.0f;
	if (is_equal(x,1.0f)) return 1.0f;
	while (1) {
		val=(left+right)/2.0f;
		v=val*val;
		if (is_equal(v,x)) break;
		if (is_equal(val,_val)) break;
		if (v<x) left=val;
		else right=val;
		_val=val;
	}
	return val;
}

/*
-------------------------
DP(Dynamic Programming)
-------------------------
*/

int w[MAXN],v[MAXN],c[MAXN],f[MAXW];

/* 0-1 knapsack */
void zero_one() {
	for (rint i=1;i<=N;++i)
	for (rint j=W;j>=w[i];--j)
	f[j]=MAXV(f[j],f[j-w[i]]+v[i]);
}

/* multiple knapsack */
void multiple() {
	for (rint i=1;i<=N;++i)
	for (rint j=1;j<=c[i];++j)
	for (rint k=W;k>=w[i];--k)
	f[k]=MAXV(f[k],f[k-w[i]]+v[i]);
}

/* complete knapsack */
void complete() {
	for (rint i=1;i<=N;++i)
	for (rint j=w[i];j<=W;++j)
	f[j]=MAXV(f[j],f[j-w[i]]+v[i]);
}

//Non-contiguous Longest Common Subsequence (LCS)
int lcs(string &s,string &t) {
	int ssize=s.size(),tsize=t.size();
	int dp[ssize][tsize];
	for (rint i=0;i<ssize;++i)
	for (rint j=0;j<tsize;++j) {
		int x=0;if (i>0) x=dp[i-1][j];
		int y=0;if (j>0) y=dp[i][j-1];
		int z=(s[i]==t[j]);
		if (i>0 && j>0) z+=dp[i-1][j-1];
		dp[i][j]=MAXV(MAXV(x,y),z);
	}
	return dp[ssize-1][tsize-1];
}

/*
----------------
Hash
----------------
*/
typedef struct node {
	int key,value;
	struct node *next;
} node;
node table[MOD];

/* table_idx=hash(key) */
uint elf_hash(const char *key) {
	ull g,h=0;
	while (*key) {
		h=(h<<4)+*key++;
		g=h&0xF0000000L;
		if (g) h^=g>>24;
		h&=~g;
	}
	return h%MOD;
}

ull bkdr_hash(const char *key) {
	uint i;ull s=131,h=0;
	while (*key) h=(h*s)+*key++;
	return h;
}

/*
----------------
Misc
----------------
*/
char buf[SIZE];

int check_palindrome(char s[],int n) {
}

void reverse_int(int s[],int n) {
	for (rint t,i=1;i<=(n>>1);++i) {
		t=s[i];s[i]=s[n-i+1];
		s[n-i+1]=t;
	}
}

void reverse_str(char s[],int n) {
	for (rint t,i=0;i<=(n>>1)-1;++i) {
		t=s[i];s[i]=s[n-i-1];
		s[n-i-1]=t;
	}
}

void reverse_int(int s[],int n) {
	for (rint i=1,j=n;i<j;++i,--j)
	swap(&s[i],&s[j]);
}

int my_itoa(int s[],int x) {
	int n;
	for (n=0;x;x/=10) s[++n]=x%10;
	reverse_int(s,n);
	return n;
}

int my_atoi(int s[],int n) {
	int x=0;
	for (int i=1;i<=n;++i) x=x*10+s[i];
	return x;
}

/* scan numbers with minus */
void scan(int x) {
	rint i,j,k,m,v,c;
	fgets(buf,sizeof(buf),stdin);
	for (i=j=0;c=buf[i];++i) {
		if (!is_digit(c) && c!='-') continue;
		m=1;if (c=='-') {m=-1;++i;}
		for (k=0;is_digit(c=buf[i]);++i) k=k*10+c-'0';
		map[x][++j]=m*k;
	}
}

/* scan numbers without minus */
void input(int s[]) {
	rint i,j,k,c;
	fgets(buf,sizeof(buf),stdin);
	for (i=j=0;c=buf[i];++i) {
		if (!is_digit(c)) continue;
		for (k=0;is_digit(c=buf[i]);++i) k=k*10+c-'0';
		s[++j]=k;
	}
}

int solve() {
	algorithm();
	return 0;
}

int main() {
	int Ans;time_t start=clock();
	int T;setbuf(stdout,NULL);scanf("%d",&T);
	for (rint t=1;t<=T;++t) {
		printf("#%d %d\n",t,Ans=solve());
	}
	time_t end=clock();
	printf("Main %f ms\n",difftime(end,start));
	return 0;
}

#ifdef __cplusplus
extern "C" {
#endif

/* c program */

#ifdef __cplusplus
}
#endif

#endif
