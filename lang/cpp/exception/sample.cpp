//normal situation
try {
	//code here
} catch (int param) {
	cout<<"int exception\n";
} catch (char param) {
	cout<<"char exception\n";
} catch (...) {
	cout<<"default exception\n";
}



//nested situation
try {
	try {
		//code here
	} catch (int n) {
		throw;
	}
} catch (...) {
	cout<<"exception occurred\n";
}


int func(int param) throw(int); //function throws only int type
int func(int param) throw();	//all exceptions call unexpected
int func(int param);		//normal exception handling
