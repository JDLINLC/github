#include<stdio.h>
int main(void)
{
	int b=0;
	
	b++?b:-b;
	printf("%d\n",b);
	return 0;
}
