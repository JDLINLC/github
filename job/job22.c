#include<stdio.h>
int main(void)
{
	int i=0,n;
	char c;

	scanf("%d\n",&n);
	while(i<n)
	{
		while(c=getchar()!='\n')
		{
			printf("%c",c);
		}
		i++;
	}

	return 0;
}
