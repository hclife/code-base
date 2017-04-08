/* employ2.h */

#ifndef __EMPLOYEE_H
#define __EMPLOYEE_H

/* Incomplete type */
typedef struct Employee Employee;

Employee* createEmployee(char*, char*, char*, int);
char* getLast(Employee*);
char* getFirst(Employee*);
char* getTitle(Employee*);
int getSalary(Employee*);
void setLast(Employee*, char*);
void setFirst(Employee*, char*);
void setTitle(Employee*, char*);
void setSalary(Employee*, int);
void printEmployee(Employee*);

#endif

