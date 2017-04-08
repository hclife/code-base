/* menu.c: Illustrates an array of function pointers */
#include <stdio.h>

extern void retrieve(void);
extern void insert(void);
extern void update(void);
extern int show_menu(void);

int main()
{
	void (*farray[])(void)={retrieve,insert,update};
	for (;;) {
		int choice=show_menu();
		if (choice>=1 && choice<=3) farray[choice-1]();
		else if (choice==4) break;
	}
	return 0;
}
