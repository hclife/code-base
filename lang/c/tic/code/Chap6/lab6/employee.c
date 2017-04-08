#include <stdio.h>
#include <string.h>
#include "employee.h"

#define MAX	10
#define SIZ	128

static char buf[SIZ];
static int num=0;
static struct Employee data[MAX];

int addEmployee()
{
	int i,c;
	if (num>=MAX) return -1;
	fflush(stdout);
	printf("Enter last name:");
	fgets(buf,sizeof(buf),stdin);
	if (strlen(buf)==1) return -1;
	for (i=0;c=buf[i];++i) {
		if (c=='\n') break;
		data[num].last[i]=c;
	}
	data[num].last[i]=0;
	printf("Enter first name:");scanf("%s",data[num].first);
	printf("Enter the title:");scanf("%s",data[num].title);
	printf("Enter the salary:");scanf("%d",&data[num].salary);
	fgets(buf,sizeof(buf),stdin);
	return num++;
}

int printEmployee(int i)
{
	if (i<0 || i>num) return -1;
	printf("#%d: {%s,%s,%s,%d}",i+1,data[i].last,
		data[i].first,data[i].title,data[i].salary);
}

int numEmployees()
{
	return num;
}
