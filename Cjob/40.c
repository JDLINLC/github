#include<stdio.h>
#define MAX 1000

void input_stirng(char *t);
void mycpy(char *s,char *t,int n);

int main(void)
{
	int N;

	scanf("%d",&N);
	for(;N>0;N--)
	{
		char t[MAX];
		int n;

		input_string(t);

		scanf("%d",&n);
		char s[n];

		mycpy(s,t,n);
	}

	return 0;
}

void input_string(char *t)
{
	int i=0;
	char ch;
	getchar();
	while((ch=getchar())!='\n')
	{
		t[i]=ch;
		i++;
	}
}

void mycpy(char *s,char *t,int n)
{
	int i=0;

	for(i=0;i<n;i++)
	{
		s[i]=t[i];
	}
	for(i=0;i<n;i++)
	{
		printf("%c",s[i]);
	}
	putchar('\n');
}
