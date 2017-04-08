#ifndef __EMPLOYEE_H
#define __EMPLOYEE_H
class Employee
{
public:
	Employee(const char *, const char *,
		const char *, const int);
	const char *getLast() const;
	const char *getFirst() const;
	const char *getTitle() const;
	const int getSalary() const;
	void setLast(const char *);
	void setFirst(const char *);
	void setTitle(const char *);
	void setSalary(const int);
	void print() const;
	~Employee();
private:
	char last[16];
	char first[11];
	char title[16];
	int salary;
};
#endif
