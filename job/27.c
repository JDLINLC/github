#include<stdio.h>
#include<string.h>

int main(void)
{
	int n;
	int i=0;
	char x[100];

	scanf("%d",&n);
	getchar();
	for(;n>0;n--)
	{
		gets(x);
		i=strlen(x);
		for(;i>0;i--)
		{
			printf("%c",x[i-1]);
		}
		putchar('\n');
	}

	return 0;
}
