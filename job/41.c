#include<stdio.h>

void transform();

int main(void)
{
	int N;

	scanf("%d",&N);
	for(;N>0;N--)
	{
		transform();
	}

	return 0;
}

void transform()
{
	char ch;
	int num = 0;

	getchar();

	while((ch=getchar())!='\n')
	{
		if(ch>='0'&&ch<='9')
		{
			num = num*16 + ch - '0';
		}
		else if(ch>='A'&&ch<='F')
		{
			num = num*16 + ch - 'A' + 10;
		}
		else if(ch>='a'&&ch<='f')
		{
			num = num*16 + ch - 'a' + 10;
		}
	}

	printf("%d\n",num);
}
