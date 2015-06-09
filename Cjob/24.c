#include<stdio.h>

void hailstone(int n);

int main(void)
{
	int n;
	
	scanf("%d",&n);
	while(n!=0)
	{
		hailstone(n);
		putchar('\n');
		scanf("%d",&n);
	}

	return 0;
}

void hailstone(int n)
{
	int i;

	printf("%5d",n);
	i=1;
	while(n!=1)
	{
		if(n%2==0)
		{
			n=n/2;
			printf("%5d",n);
		}
		else
		{
			n=3*n+1;
			printf("%5d",n);
		}
		i++;
		if(i%6==0)
		  putchar('\n');
	}
	if((i%6)!=0)
		putchar('\n');	  
}
