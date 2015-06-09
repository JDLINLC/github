#include<stdio.h>
#include<string.h>
#define MAX 1000

int input_string(char *ch);
int palindrome(char *ch,int start,int end);
void output(int x);

int main(void)
{
	int N;

	scanf("%d",&N);
	getchar();
	for(;N>0;N--)
	{
		char ch[MAX];
		int x,start=0,end=0;

		end=input_string(ch)-1;
		x=palindrome(ch,start,end);
		output(x);
	}

	return 0;
}

int input_string(char *ch)
{
	char c;
	int i=0;

	while((c=getchar())!='\n')
	{
		ch[i]=c;
		i +=1;
	}
	printf("%d",i);
	return i;
}

int palindrome(char *ch,int start,int end)
{
	printf("1:%d  %d\n",start,end);
	if(ch[start]==ch[end])
	{
		if(start>=end)
		{
			printf("2:%d %d\n",start,end);
			return 1;
		}
		else
			palindrome(ch,++start,--end);
	}
	else
		return 0;
}

void output(int x)
{
	if(x==1)
	{
		printf("Yes!\n");
	}
	else
	{
		printf("No!\n");
	}
}
