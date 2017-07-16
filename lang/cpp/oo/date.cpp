#include <iostream>
using namespace std;

class Date {
private: int year,month,day;
public:
	 Date() {}
	 Date(int y,int m,int d):year(y),month(m),day(d) {}
	 Date(const Date &D);
	 Date &operator=(const Date &D);
	 void setDate(int,int,int);
	 bool isLeapYear();
	 void print() {cout<<year<<"."<<month<<"."<<day<<endl;}
};

Date::Date(const Date &D) {
	year=D.year;
	month=D.month;
	day=D.day;
}

Date &Date::operator=(const Date &D) {
	if (&D==this) return *this;
	this->year=D.year;
	this->month=D.month;
	this->day=D.day;
	return *this;
}

#if 0
void Date::setDate(int y,int m,int d) {
	year=y;month=m;day=d;
}
#else
//This will result runtime error without *this
void Date::setDate(int year,int month,int day) {
	this->year=year;
	this->month=month;
	this->day=day;
}
#endif

bool Date::isLeapYear() {
	if (year%400==0) return true;
	return year%4==0 && year%100!=0;
}

int main() {
	while (1) {
		int y,m,d;
		cin>>y>>m>>d;
		//Date t(y,m,d);
		Date t;t.setDate(y,m,d);
		t.print();
		cout<<std::boolalpha;
		cout<<t.isLeapYear()<<endl;
	}
	return 0;
}
