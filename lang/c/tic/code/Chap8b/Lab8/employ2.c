/* employ2.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "employ2.h"

#define MAX	10
#define LEN	sizeof(Employee)

struct Employee
{
    char last[16];
    char first[11];
    char title[16];
    int salary;
};

Employee *createEmployee(char *last, char *first,
			 char *title, int salary)
{
	Employee *emp=(Employee *)malloc(LEN);
	if (!emp) return NULL;
	strcpy(emp->last,last);
	strcpy(emp->first,first);
	strcpy(emp->title,title);
	emp->salary=salary;
	return emp;
}

char *getLast(Employee *emp)
{
	if (!emp) return "";
	return emp->last;
}

char *getFirst(Employee *emp)
{
	if (!emp) return "";
	return emp->first;
}

char *getTitle(Employee *emp)
{
	if (!emp) return "";
	return emp->title;
}

int getSalary(Employee *emp)
{
	if (!emp) return 0;
	return emp->salary;
}

void setLast(Employee *emp, char *last)
{
	if (!emp) return;
	strcpy(emp->last,last);
}

void setFirst(Employee *emp, char *first)
{
	if (!emp) return;
	strcpy(emp->first,first);
}

void setTitle(Employee *emp, char *title)
{
	if (!emp) return;
	strcpy(emp->title,title);
}

void setSalary(Employee *emp, int salary)
{
	if (!emp) return;
	emp->salary=salary;
}

void printEmployee(Employee *emp)
{
	if (!emp) {
		printf("{}");
		return;
	}
	printf("{%s,%s,%s,%d}",emp->last,emp->first,
			emp->title,emp->salary);
}
