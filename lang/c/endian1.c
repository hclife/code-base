#include <stdio.h>
#include <stdbool.h>

union {
	int num;
	char c;
} utest;

bool isBigEndian() {
	utest.num=0x01000002;
	return utest.c==0x01;
}

int main() {
	if (isBigEndian()==true) printf("big-endian\n");
	else printf("little-endian\n");
	return 0;
}
