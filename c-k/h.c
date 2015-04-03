#include<stdio.h>
#include<string.h>
void h(char *n);
void p(int start,int end);
void t(int num);
int main(void)
{
	int start,end;
	char n[100];

	printf("Enter a number to start and a number to end(q to quit):\n");
	while(scanf("%d %d",&start,&end)==2)
	{
		p(start,end);
	}

	return 0;
}


void h(char *n)
{
	char t[100];
	int i,j=0,l;

	l=strlen(n);
	n[l]='\0';
	for(i=0;i<l;i++)
	{
		t[l-i-1]=n[i];
	}
	t[l]='\0';
	if(strcmp(t,n)==0)
	{
		printf("%s\t",n);
	}
}


void p(int start,int end)
{
	int i=0;

	if(start>end)
	{
		printf("Your enter is wrong!\nPlease try again(q to quit):\n");
	}
	else
	{
		for(start;start<=end;start++)
		{
			t(start);
		}
		printf("\nPlease enter again(q to quit:)\n");
	}
}


void t(int num)
{
	char s[100],o[100];
	int i=0,j;

	s[i]=num%10+48;
	while(num/10!=0)
	{
		i +=1;
		num /=10;
		s[i]=num%10+48;
	}
	s[i+1]='\0';
	for(j=0;j<=i;j++)
	{
		o[i-j]=s[j];
	}
	o[i+1]='\0';
	h(o);
}	
