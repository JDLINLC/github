#include<stdio.h>
void fb(int x);
int main(void)
{
	int x;

	do
	{
		scanf("%d",&x);
		if(x<3&x!=0)
		  printf("Error!\n");
		else
		{
		  fb(x);
		  printf("\n");
		}
	}while(x!=00);

	return 0;
}
void fb(int x)
{
	int num[x],i;
	int j=0,k=0;

	num[0]=1;
	num[1]=1;

	for(i=2;i<=x;i++)
	{
		num[i]=num[i-1]+num[i-2];
	}

	while(j<x)
	{
		printf("%10d",num[j]);
		k++;
		if(k==8)
		{
		  putchar('\n');
		  k=0;
		}
		j++;
	}
}
