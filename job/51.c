#include<stdio.h>
int main(void)
{
	int N,n;

	scanf("%d",&N);
	for(;N>0;N--)
	{
		int n;
		scanf("%d",&n);

		int people[n],*pti=people,i=0,j=0,k=n;
		
		for(;i<n;i++)
			*(pti+i)=i+1;

		while(k!=1)
		{
			i=1;
			while(i<3)
			{
				if(*(pti+j)==0)
				  j++;
				else
				  i++,j++;
				if(j==n)
				  j=0;
			}
			while(*(pti+j)==0)
			{
				j++;
				if(j==n)
				  j=0;
			}

			*(pti+j)=0;
			k--;
		}

		for(i=0;i<n;i++)
			if(*(pti+i)!=0)
			  printf("%d\n",*(pti+i));

	}

	return 0;
}
