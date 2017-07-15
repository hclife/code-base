#include <stdio.h>
#include <string.h>

int main() {
	char str[]="- This is, a sample string.";
	printf("splitting string \"%s\" into tokens:\n",str);
	char *pch=strtok(str," ,.-");
	while (pch) {
		puts(pch);
		pch=strtok(NULL, " ,.-");
	}
	return 0;
}
