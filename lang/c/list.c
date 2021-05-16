#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LEN_LIST	sizeof(struct list)

typedef struct list {
	struct list *next;
	int data;
} list;

struct list *list_init(int data) {
	struct list *p=(list *)malloc(LEN_LIST);
	if (!p) {
		printf("malloc failed\n");
		return NULL;
	}
	p->next=NULL;
	p->data=data;
	return p;
}

void list_add_back(struct list *head,int data) {
	if (!head) {
		head=list_init(data);
		return;
	}
	struct list *p;
	for (p=head;p->next;p=p->next);
	p->next=list_init(data);
}

void list_print(struct list *head) {
	if (!head) return;
	for (struct list *p=head;p;p=p->next)
		printf("%d ",p->data);
	putchar('\n');
}

void list_free(struct list **head) {
	if (!*head) return;
	struct list *p,*next;
	for (p=next=*head;p;p=next) {
		next=p->next;
		free(p);
	}
	*head=NULL;
}

int main() {
	struct list *head=list_init(2);
	if (!head) return 1;
	list_add_back(head,10);
	list_add_back(head,20);
	list_add_back(head,30);
	list_print(head);
	list_free(&head);
	list_print(head);
	return 0;
}
