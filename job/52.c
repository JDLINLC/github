#include<stdio.h>
#define MAX 81
int main(void)
{
	int n,i=0,j=0,k=0;
	
	scanf("%d",&n);

	while(n!=0)
	{
		getchar();
		k=0;
		char ch_str[n][MAX],*ptr[MAX],str[n*MAX],*ptr1,ch;

		for(i=0;i<n;i++)
			ptr[i]=ch_str[i];
		ptr1=str;

		for(i=0;i<n;i++)
		{
			j=0;
			while((ch=getchar())!='\n')
			{
			  ch_str[i][j]=ch;
			  j++;
			}
			ch_str[i][j]='\0';
		}

		for(i=0;i<n;i++)
		{
			j=0;
			while(*(ptr1+k)=*(*(ptr+i)+j))
			  k++,j++;
		}

		printf("%s\n",ptr1);

		scanf("%d",&n);
	}

	return 0;
}
