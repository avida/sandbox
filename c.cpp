#include <stdio.h>
int main()
{
	int a = 12;
	int valbit = a & (-a);
	printf("a = %p\n", a);
	printf("-a = %p\n", -a);
	printf("bia = %p\n", valbit);

	return 0;

}