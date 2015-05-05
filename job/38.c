#include<stdio.h>
#define SWAP(a,b) (a=a+b,b=a-b,a=a-b)
#define LEN 20

void input();
void swap();
void output();

int n,k;
int u[LEN];
int i=0,j=0;

int main(void)
{
	scanf("%d",&n);

	while(n!=0)
	{
		scanf("%d",&k);

		input();
		swap();
		output();

		scanf("%d",&n);
	}

	return 0;
}

void input()
{
	for(i=0;i<LEN;i++)
	{
		u[i]=0;
	}
	for(i=0;i<n;i++)
	{
		scanf("%d",&u[i]);
	}
}

void swap()
{
	for(i=k-1;i>=0;i--)
	{
		for(j=i;j<(i+n-k);j++)
		{
			SWAP(u[j],u[j+1]);
		}
	}	  
}

void output()
{
	for(i=0;i<n;i++)
	{
		if(i==(n-1))
		{
			printf("%d\n",u[i]);
		}
		else
		{
			printf("%d ",u[i]);
		}
	}
}
