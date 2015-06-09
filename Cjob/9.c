#include<stdio.h>
int main(void)
{
	unsigned short int x;
	int n,i=0;

	scanf("%d",&n);
	while(i<n)
	{
		scanf("%hu",&x);
		printf("%hu",(x>>12&0xf)|(x<<12&0xf000)|(x&0xff0));
		printf("\n");
		i++;
	}
}
