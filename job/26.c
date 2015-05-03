#include<stdio.h>
#include<string.h>

int strlen_1(char *x);

int main(void)
{
	int i,n;
	char x[81];

	scanf("%d",&n);
	getchar();
	for(i=0;i<n;i++)
	{
		fgets(x,81,stdin);
		printf("%d\n",strlen_1(x));
	}

	return 0;
}

int strlen_1(char *x)
{
	if(*x=='\0')
		return -1;
	else
		return (strlen_1(++x)+1);
}
