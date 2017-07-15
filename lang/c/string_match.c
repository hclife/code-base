#include <stdio.h>
#include <string.h>

int main() {
	int i, j, k;
	const char *p = "whateverso";
	const char *s[] = {"none","monday", "tuesday","wednesday",
			"thursday","friday", "saturday", "sunday",
			NULL};
	char str[20];
	int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

#if 1
	printf("%lu\n", sizeof(p));
	printf("%lu\n", sizeof(*p));
	printf("%lu\n", strlen(p));
	puts(p);
#endif

#if 0
	printf("%lu\n", sizeof(a) / sizeof(a[0]));
	for (i = 1; s[i]; i++) puts(s[i]);
#endif

	freopen("string_match.txt","r",stdin);
	scanf("%s", str);

	for (i = 1; s[i]; i++) {
		if (!strcmp(str, s[i])) break;
	}
	printf("%s match s[%d]\n", str, i);

	return 0;
}
