#include<stdio.h>
void sort(int *num,int n);
int main(void)
{
	int N,n;
	int i;

	scanf("%d",&N);
	for(;N>0;N--)
	{
		scanf("%d",&n);
		int num[n];
		for(i=0;i<n;i++)
		{
			scanf("%d",&num[i]);
		}
		sort(num,n);
	}
	return 0;
}
void sort(int *num,int n)
{
	int i,j;
	int *ptr;
	
	ptr=num;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(*(ptr+i)<*(ptr+j))
			{
				int tmp;
				tmp=num[i];
				num[i]=num[j];
				num[j]=tmp;
			}
			
		}
	}
	for(i=0;i<n;i++)
	{
		printf("%d",num[i]);
		if(i==n-1)
		  printf("\n");
		else
		  printf(" ");
	}
}
