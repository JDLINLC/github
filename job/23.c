#include<stdio.h>

int jc(int x);

int main(void)
{
	int n,i;
	double sum=0;

	scanf("%d",&n);
	while(n!=0)
	{
		if(n<0)
		{
			printf("Error!\n");
		}
		else
		{
			for(i=1;i<=n;i++)
			{
				sum +=(1.0/(jc(i)));
			}
			printf("s = %.8lf\n",sum);
		}
		scanf("%d",&n);
		sum=0;
	}


}

int jc(int x)
{
	int jc=1;
	int i;

	for (i=1;i<=x;i++)
	{
		jc *=i;
	}

	return jc;
}
