#include <iostream>
#include <cstring>
using namespace std;

class String {
private:
    char *m_data;
public:
    String(const char *str=nullptr);
    String(const String &S);
    String &operator=(const String &S);
    ~String();
    void show();
};

String::String(const char *str) {
    cout<<"constructor\n";
    size_t size=strlen(str)+1;
    m_data=new char[size];
    strncpy(m_data,str,size);
}

String::String(const String &S) {
    cout<<"copy constructor\n";
    size_t size=strlen(S.m_data)+1;
    m_data=new char[size];
    strncpy(m_data,S.m_data,size);
}

String::~String() {
    cout<<"destructor\n";
    if (m_data) {
	delete[] m_data;
	m_data=nullptr;
    }
}

String& String::operator=(const String &S) {
    cout<<"operator=\n";
    if (this==&S) return *this;
    if (m_data) delete[] m_data;
    size_t size=strlen(S.m_data)+1;
    m_data=new char[size];
    strncpy(m_data,S.m_data,size);
    return *this;
}

void String::show() {
    cout<<m_data<<endl;
}


int main() {
    String s("anewstring"); //constructor
    String x("todayisbig"); //constructor
    String t(s); //copy constructor
    String w=s;  //copy constructor
    w=x;	 //operator=
    s.show();
    t.show();
    w.show();
    return 0;
}
