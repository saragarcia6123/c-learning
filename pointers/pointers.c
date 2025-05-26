#include<stdio.h>
int main()
{
	int a;
	int *p;
	p = &a;
	*p = 5;
	printf("%d\n", p);
	printf("%d\n", &a);
	printf("%d\n", *p);
	printf("%d\n", a);
	printf("%d\n", &p);
	printf("size of a: %d bytes\n", sizeof(a));
	printf("size of p: %d bytes\n", sizeof(p));

}
