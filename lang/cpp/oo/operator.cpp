#include <iostream>
using namespace std;

#if 0
#define MEMBER
#else
#define FRIEND
#endif

//Normal operators overloading
class A {
public:
 A(int d):data(d){}
 void print() {cout<<data<<endl;}
#ifdef MEMBER
 A operator+(A&);//成员函数
 A operator-(A&);
 A operator*(A&);
 A operator/(A&);
 A operator%(A&);
#endif
#ifdef FRIEND
 friend A operator+(A&,A&);//友元函数
 friend A operator-(A&,A&);
 friend A operator*(A&,A&);
 friend A operator/(A&,A&);
 friend A operator%(A&,A&);
#endif
private:
 int data;
};

#ifdef MEMBER
A A::operator+(A &a) {
 return A(data+a.data);
}
A A::operator-(A &a) {
 return A(data-a.data);
}
A A::operator*(A &a) {
 return A(data*a.data);
}
A A::operator/(A &a) {
 return A(data/a.data);
}
A A::operator%(A &a) {
 return A(data%a.data);
}
#endif

#ifdef FRIEND
A operator+(A &a1,A &a2) {
 return A(a1.data+a2.data);
}
A operator-(A &a1,A &a2) {
 return A(a1.data-a2.data);
}
A operator*(A &a1,A &a2) {
 return A(a1.data*a2.data);
}
A operator/(A &a1,A &a2) {
 return A(a1.data/a2.data);
}
A operator%(A &a1,A &a2) {
 return A(a1.data%a2.data);
}
#endif

int main() {
 A a1(1),a2(2),a3(3);
 a1=a2+a3;
 a1.print();
 return 0;
}

//relation & logic operators overload
//member or friend function
bool operator == (const A& ); 
bool operator != (const A& );
bool operator < (const A& );
bool operator <= (const A& );
bool operator > (const A& );
bool operator >= (const A& );
bool operator || (const A& );
bool operator && (const A& );
bool operator ! ();

//single parameter operators overload
//member or friend function
A& operator + ();
A& operator - ();
A* operator & ();
A& operator * ();

//self increment/decrement operators
//member or friend function
A& operator ++ ();//前置++
A operator ++ (int);//后置++
A& operator --();//前置--
A operator -- (int);//后置--

//bit operators overload
//member or friend function
A operator | (const A& );
A operator & (const A& );
A operator ^ (const A& );
A operator << (int i);
A operator >> (int i);
A operator ~ ();

//assign operators overload
//member or friend function
A& operator += (const A& );
A& operator -= (const A& ); 
A& operator *= (const A& );
A& operator /= (const A& );
A& operator %= (const A& );
A& operator &= (const A& );
A& operator |= (const A& );
A& operator ^= (const A& );
A& operator <<= (int i);
A& operator >>= (int i);

//memory operators overload
//member or friend function
void *operator new(size_t size);
void *operator new(size_t size, int i);
void *operator new[](size_t size);
void operator delete(void*p);
void operator delete(void*p, int i, int j);
void operator delete [](void* p);

//special operators overload
//member function only
A& operator = (const A& );
char operator [] (int i);//返回值不能作为左值
const char* operator () ();
T operator -> ();
operator char* () const;
operator int ();
operator const char () const;
operator short int () const;
operator long long () const;

//stream operators overload
//friend function only
friend inline ostream &operator << (ostream&, A&);//输出流
friend inline istream &operator >> (istream&, A&);//输入流

/*
两种重载方式的比较：
一般情况下，单目运算符最好重载为类的成员函数；双目运算符
则最好重载为类的友元函数。
以下一些双目运算符不能重载为类的友元函数：=、()、[]、->。
类型转换函数只能定义为一个类的成员函数而不能定义为类的友元函数。 
C++提供4个类型转换函数：reinterpret_cast（在编译期间实现转换）、
const_cast（在编译期间实现转换）、stactic_cast（在编译期间实现转换）、
dynamic_cast（在运行期间实现转换，并可以返回转换成功与否的标志）。
若一个运算符的操作需要修改对象的状态，选择重载为成员函数较好。
若运算符所需的操作数（尤其是第一个操作数）希望有隐式类型转换，
则只能选用友元函数。
当运算符函数是一个成员函数时，最左边的操作数（或者只有最左边的操作数）
必须是运算符类的一个类对象（或者是对该类对象的引用）。如果左边的操作数
必须是一个不同类的对象，或者是一个内部类型的对象，该运算符函数必须作为
一个友元函数来实现。当需要重载运算符具有可交换性时，选择重载为友元函数。

注意事项：
除了类属关系运算符”.“、成员指针运算符”.*“、作用域运算符”::“、
sizeof运算符和三目运算符”?:“以外，C++中的所有运算符都可以重载。
重载运算符限制在C++语言中已有的运算符范围内的允许重载的运算符之中，
不能创建新的运算符。
运算符重载实质上是函数重载，因此编译程序对运算符重载的选择，
遵循函数重载的选择原则。
重载之后的运算符不能改变运算符的优先级和结合性，也不能改变运算符操作数
的个数及语法结构。
运算符重载不能改变该运算符用于内部类型对象的含义。它只能和用户自定义类型
的对象一起使用，或者用于用户自定义类型的对象和内部类型的对象混合使用时。
运算符重载是针对新类型数据的实际需要对原有运算符进行的适当的改造，重载
的功能应当与原有功能相类似，避免没有目的地使用重载运算符。
*/
