/* employ2.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "employ2.h"

#define MAX	10
#define LEN	sizeof(struct Employee)


struct Employee *createEmployee(char *last, char *first,
				char *title, int salary)
{
	struct Employee *emp=(struct Employee *)malloc(LEN);
	if (!emp) return NULL;
	strcpy(emp->last,last);
	strcpy(emp->first,first);
	strcpy(emp->title,title);
	emp->salary=salary;
	return emp;
}

char *getLast(struct Employee *emp)
{
	if (!emp) return "";
	return emp->last;
}

char *getFirst(struct Employee *emp)
{
	if (!emp) return "";
	return emp->first;
}

char *getTitle(struct Employee *emp)
{
	if (!emp) return "";
	return emp->title;
}

int getSalary(struct Employee *emp)
{
	if (!emp) return 0;
	return emp->salary;
}

void setLast(struct Employee *emp, char *last)
{
	if (!emp) return;
	strcpy(emp->last,last);
}

void setFirst(struct Employee *emp, char *first)
{
	if (!emp) return;
	strcpy(emp->first,first);
}

void setTitle(struct Employee *emp, char *title)
{
	if (!emp) return;
	strcpy(emp->title,title);
}

void setSalary(struct Employee *emp, int salary)
{
	if (!emp) return;
	emp->salary=salary;
}

void printEmployee(struct Employee *emp)
{
	if (!emp) {
		printf("{}");
		return;
	}
	printf("{%s,%s,%s,%d}",emp->last,emp->first,
			emp->title,emp->salary);
}
