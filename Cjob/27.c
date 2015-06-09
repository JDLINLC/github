#include<stdio.h>
#include<string.h>

void my_printf(char *x);

int main(void)
{
	int n;
	char x[100];

	scanf("%d",&n);
	getchar();
	for(;n>0;n--)
	{
		gets(x);
		my_printf(x);
		putchar('\n');
	}

	return 0;
}

void my_printf(char *x)
{
	if(*x=='\0')
		;
	else
	{
		my_printf(x+1);
		putchar(*x);
	}
}
