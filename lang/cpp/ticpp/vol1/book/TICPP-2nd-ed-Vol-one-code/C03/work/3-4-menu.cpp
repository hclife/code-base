#include <iostream>
using namespace std;

void menu_left()
{
	char c;
	cout<<"LEFT MENU:"<<endl;
	cout<<"select a/b: ";
	cin>>c;
	switch (c) {
	case 'a':
		cout<<"You chose a"<<endl;
		break;
	case 'b':
		cout<<"You chose b"<<endl;
		break;
	default:
		cout<<"You didn't choose a/b!"<<endl;
		break;
	}
}

void menu_right()
{
	char c;
	cout<<"RIGHT MENU:"<<endl;
	cout<<"select c/d: ";
	cin>>c;
	switch (c) {
	case 'c':
		cout<<"You chose c"<<endl;
		break;
	case 'd':
		cout<<"You chose d"<<endl;
		break;
	default:
		cout<<"You didn't choose c/d!"<<endl;
		break;
	}
}

int main()
{
	char c;
	bool loop=true;
	while (loop==true) {
		cout<<"MAIN MENU:"<<endl;
		cout<<"l:left r:right q:quit -> ";
		cin>>c;
		switch (c) {
		case 'q':
			cout<<"Quitting menu..."<<endl;
			loop=false;
			break;
		case 'l':
			menu_left();
			break;
		case 'r':
			menu_right();
			break;
		default:
			cout<<"You must type l/r/q!"<<endl;
			break;
		}
	}
	return 0;
}

