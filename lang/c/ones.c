//count how many number of ones
#include <stdio.h>

size_t num_of_ones(size_t x) {
	size_t n=0;
	while (x) {
		++n;
		x=x&(x-1);
	}
	return n;
}

int main() {
	size_t x;scanf("%lu",&x);
	printf("%lu\n",num_of_ones(x));
	return 0;
}
