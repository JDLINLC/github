#include<stdio.h>
int main(void)
{
	int a,b=1;

	while(scanf("%d",&a)==1)
	{
		printf("%d\n", (a%3==0 && a%10==5)?1:0);
	}
	return 0;
}		
