#include<stdio.h>
int main(void)
{
	int n,i=0;
	char ch;

	scanf("%d",&n);
	while(i<n)
	{
		getchar();
		ch=getchar();
		if(ch>='0'&&ch<='9')
		{
			printf("%c",ch);
		}
		else if(ch>='a'&&ch<='f')
		{
			printf("%d",ch-'a'+10);
		}
		else if(ch>='A'&&ch<='F')
		{
			printf("%d",ch-'A'+10);
		}
		else
		{
			printf("%d",ch);
		}
		printf("\n");
		i++;
	}
	return 0;
}
