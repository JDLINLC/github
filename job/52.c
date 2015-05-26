#include<stdio.h>
#define MAX 81
int main(void)
{
	int n,i=0;
	
	scanf("%d",&n);

	while(n!=0)
	{
		int k=0;
		char ch_str[n][MAX],*ptr[MAX],str[n*MAX],*ptr1;

		for(i=0;i<n;i++)
			ptr[i]=ch_str[i];
		ptr1=str;

		for(i=0;i<n;i++)
		{
			scanf("%s",ptr[i]);
		}

		for(i=0;i<n;i++)
		{
			int j=0;
			while(*(ptr1+k)=*(*(ptr+i)+j))
			  k++,j++;
		}

		printf("%s\n",ptr1);

		scanf("%d",&n);
	}

	return 0;
}
