//Virtual functions
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#include <string>
static int prof_cur_id=0;
static int stud_cur_id=0;
static const int max_subjects=6;

class Person {
public:    
    string name;
    int age;
    virtual void getdata()=0;
    virtual void putdata()=0;
};

class Professor: public Person {
public:    
    int publications;    
    int cur_id;
    Professor() {
        ++prof_cur_id;
    }
    void getdata() {
        cin>>name>>age;
        cin>>publications;
        cur_id=prof_cur_id;
    }
    void putdata() {
        cout<<name<<' '<<age<<' ';      
        cout<<publications<<' '<<cur_id<<endl;
    }
};

class Student: public Person {
public:    
    int marks[6];
    int sum;
    int cur_id;
    Student() {
        ++stud_cur_id;
    }
    void getdata() {
        cin>>name>>age;
        sum=0;
        for (int i=0;i<6;++i) {
            cin>>marks[i];
            sum+=marks[i];
        }
        cur_id=stud_cur_id;
    }
    void putdata() {
        cout<<name<<' '<<age<<' ';      
        cout<<sum<<' '<<cur_id<<endl;
    }
};

int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}

