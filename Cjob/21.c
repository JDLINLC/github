#include<stdio.h>

int jc(int i);

int main(void)
{
	int n,sum=0;
	int i;

	scanf("%d",&n);
	while(n!=0)
	{
		if(n<0)
		  printf("Error!\n");
		else
		{
			for(i=1;i<=n;i++)
			{
				sum +=jc(i);
			}
			printf("%d\n",sum);
		}
		scanf("%d",&n);
		sum=0;
	}

	return 0;
}

int jc(int i)
{
	int sum=1;
	int j;

	for(j=1;j<=i;j++)
	{
		sum *=j;
	}

	return sum;
}
