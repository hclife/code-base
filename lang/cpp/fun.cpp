struct Test  
{  
	Test(int ) { }  
	Test() { }  
	void fun() { }  
};  

int main(void)  
{  
	Test a(1);  
	a.fun();  
	Test b();  
	b.fun();  
	return 0;  
}  
