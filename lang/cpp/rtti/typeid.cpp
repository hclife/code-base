#include <iostream>
#include <typeinfo>
using namespace std;

class Animal{
public:
	virtual void display(){}
};
class Cow:public Animal{};
class Dog:public Animal{};

int main() {
    Animal *anm;
    Cow cw;
    Dog dg;
    cout << "type of anm is : "<<typeid(anm).name()<<endl;
    cout << "type of cw is : "<<typeid(cw).name()<<endl;
    cout << "type of dg is : "<<typeid(dg).name()<<endl;

    //after initializing base pointer with 
    //address of derived class object
    //assigns anm with address of cw.since Animal 
    //is virtual, anm is now type of Cow
    anm = &cw;
    cout<<"type of *anm when pointing to cw is: ";
    cout<<typeid(*anm).name()<<endl;
    anm = &dg;
    cout<<"type of *anm when pointing to dg is: ";
    cout<<typeid(*anm).name()<<endl;
    return 0;
}
