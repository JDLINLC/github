#include<stdio.h>
int main(void)
{
	int n,k;

	scanf("%d",&n);

	while(n!=0)
	{
		int u[n],i=0;

		scanf("%d",&k);
		getchar();
		while(scanf("%d",&u[i])&&i<(n-1))
		{
			i++;
		}

		for(i=0;i<(n-k);i++)
		{
			u[i]=i+k+1;
		}
		for(i=0;i<k;i++)
		{
			u[i+(n-k)]=i+1;
		}
		
		for(i=0;i<n;i++)
		{
			if(i==(n-1))
			{
				printf("%d\n",u[i]);
			}
			else
				printf("%d ",u[i]);
		}
		scanf("%d",&n);
	}

	return 0;
}
