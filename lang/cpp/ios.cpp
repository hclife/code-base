#include <iostream>
using namespace std;

class Date {
public:
	Date(int year,int month,int day)
	:_year(year),_month(month),_day(day) {}
	void writeTo(std::ostream &os) const {
		os<<_year<<'-'<<_month<<'-'<<_day<<endl;
	}
private:
	int _year,_month,_day;
};

std::ostream& operator<<(std::ostream &os,const Date &date) {
	date.writeTo(os);
	return os;
}

int main() {
	Date date(2011,4,3);
	std::cout<<date<<endl;
	return 0;
}
