#include<stdio.h>
void change(int *x,int n);
int main(void)
{
	int N,n;
	int i;

	scanf("%d",&N);
	for(;N>0;N--)
	{
		scanf("%d",&n);
		int x[n],*ptr;
		ptr=x;

		for(i=0;i<n;i++)
		{
			scanf("%d",(ptr+i));
		}

		change(ptr,n);

		for(i=0;i<n;i++)
		{
			printf("%d",*(ptr+i));
			if(i==(n-1))
				printf("\n");
			else
				printf(" ");
		}
	}

	return 0;
}
void change(int *x,int n)
{
	int mid=0,i=0;

	mid=n/2;
	for(i=0;i<mid;i++)
	{
		int tmp;
		tmp=x[i];
		x[i]=x[n-i-1];
		x[n-i-1]=tmp;
	}
}
