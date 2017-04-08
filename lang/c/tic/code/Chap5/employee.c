/* employee.c: Defines an Employee structure */
#include <stdio.h>
#include <string.h>

struct Employee {
	char last[16],first[11];
	char title[16];int salary;
};

char buf[128];
struct Employee data[64];

int main()
{
	int i,j;
	for (i=0;i<64;++i) {
		fflush(stdout);
		printf("For the %dth Employee\n",i+1);
		printf("Enter last name: ");
		fgets(buf,sizeof(buf),stdin);
		for (j=0;buf[j] && buf[j]!='\n';++j)
			data[i].last[j]=buf[j];
		data[i].last[j]=0;
		if (!strlen(data[i].last)) break;
		printf("Enter first name: ");scanf("%s",data[i].first);
		printf("Enter the title: ");scanf("%s",data[i].title);
		printf("Enter the salary: ");scanf("%d",&data[i].salary);
		fgets(buf,sizeof(buf),stdin);
	}
	for (j=0;j<i;++j) {
		printf("%d: {%s,%s,%s,%d}\n",j+1,data[j].last,
				data[j].first,data[j].title,data[j].salary);
	}
	return 0;
}
