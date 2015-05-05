#include<stdio.h>

void input(int n,int *u);
void sort(int n,int *u);
void output(int n,int *u);

int i=0;

int main(void)
{
	int n;

	scanf("%d",&n);
	while(n!=0)
	{
		int u[n];

		input(n,u);
		sort(n,u);
		output(n,u);

		scanf("%d",&n);
	}

	return 0;
}

void input(int n,int *u)
{
	for(i=0;i<n;i++)
	{
		scanf("%d",&u[i]);
	}
}

void sort(int n,int *u)
{
	int j;
	int temp;

	for(i=0;i<n-1;i++)
	{
		for(j=i;j<n;j++)
		{
			if(u[i]>u[j])
			{
				temp=u[i];u[i]=u[j];u[j]=temp;
			}
		}
	} 
}

void output(int n,int *u)
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
