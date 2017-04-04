#include <iostream>

void print(const char *s) {
    while (*s) {
	if (*s=='%') {
	    if (*(s+1)=='%') ++s;
	    else throw std::runtime_error("invalid \
		format string: missing arguments");
	}
	std::cout<<*s++;
    }
}

template<typename T,typename... Args>
void print(const char *s,T value,Args... args) {
    while (*s) {
	if (*s=='%') {
	    if (*(s+1)=='%') ++s;
	    else {
		std::cout<<value;
		//call even when *s==0 to detect extra arguments
		print(s+1,args...);
		return;
	    }
	}
	std::cout<<*s++;
    }
}

int main() {
    print("This % is c++ from %.\n",100,"stroustrup");
    return 0;
}

