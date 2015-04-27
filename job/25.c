#include<stdio.h>

void digit(long int x,int n);

int main(void)
{
	long int x;
	int n;

	scanf("%ld%d",&x,&n);
	while(x!=0||n!=0)
	{
		digit(x,n);
		scanf("%ld%d",&x,&n);
	}

	return 0;
}

void digit(long int x,int n)
{
	int num[100];
	int i=1;
	long int s=x;

	num[0]=x%10;
	while((x=(x/10))!=0)
	{
		num[i]=x%10;
		i++;
	}
	if(n>i||n<1)
	  printf("digit(%ld,%d)=%d\n",s,n,-1);
	else
	{
		if(s<0)
			printf("digit(%ld,%d)=%d\n",s,n,-num[n-1]);
		else
			printf("digit(%ld,%d)=%d\n",s,n,num[n-1]);
	}
}
