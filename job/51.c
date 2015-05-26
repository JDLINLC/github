#include<stdio.h>
int main(void)
{
	int N,n;
	int i=0,j=0,k=0,m=0;

	scanf("%d",&N);
	for(;N>0;N--)
	{
		scanf("%d",&n);
		int x[n],*ptr;
		m=n;
		ptr=x;

		for(i=1;i<=n;i++)
		{
			x[i]=i;
		}

		while(m>1)
		{
			for(j=0;j<3;j++)
			{
				k++;
				if(k==n)
				{
					k=0;
				}
				if(*(ptr+k)==0)
				{
					k++;
				}
			}
			*(ptr+k)=0;
			m -=1;
		}

		for(i=0;i<n;i++)
		{
			if(*(ptr+i)!=0)
			{
				printf("%d",*(ptr+i));
			}
		}

	}

	return 0;
}
