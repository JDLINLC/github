#include<stdio.h>

int gy(int a,int b);

int gb(int a,int b);

int main(void)
{
	int a,b;

	scanf("%d%d",&a,&b);
	while((a!=0)||(b!=0))
	{
		printf("%d %d\n",gy(a,b),gb(a,b));
		scanf("%d%d",&a,&b);
	}

	return 0;
}

int gy(int a,int b)
{
	int i,gy=1;

	if(a>b)
	{
		for(i=2;i<=b;i++)
		{
			if(a%i==0&&b%i==0)
				gy=i;
		}
	}
	else
	{
		for(i=2;i<=a;i++)
		{
			if(a%i==0&&b%i==0)
				gy=i;
		}
	}

	return gy;
}

int gb(int a,int b)
{
	int gb;
	
	gb=(a*b)/gy(a,b);

	return gb;
}
