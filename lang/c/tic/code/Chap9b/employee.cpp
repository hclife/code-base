#include "employee.h"
#include <iostream>
#include <cstring>

Employee::Employee(const char *la, const char *fi,
		   const char *ti, const int sa)
{
	strcpy(last,la);
	strcpy(first,fi);
	strcpy(title,ti);
	salary=sa;
}

const char* Employee::getLast() const
{
	if (last) return last;
	else throw "last undefined";
}

const char* Employee::getFirst() const
{
	if (first) return first;
	else throw "first undefined";
}

const char* Employee::getTitle() const
{
	if (title) return title;
	else throw "title undefined";
}

const int Employee::getSalary() const
{
	if (salary>0) return salary;
	else throw "salary undefined";
}

void Employee::setLast(const char *la)
{
	strcpy(last,la);
}

void Employee::setFirst(const char *fi)
{
	strcpy(first,fi);
}

void Employee::setTitle(const char *ti)
{
	strcpy(title,ti);
}

void Employee::setSalary(const int sa)
{
	salary=sa;
}

void Employee::print() const
{
	std::cout<<"{"<<last<<","<<first<<","
		 <<title<<","<<salary<<"}";
}

Employee::~Employee()
{
	salary=-1;
}
