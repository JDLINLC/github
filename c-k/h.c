#include<stdio.h>
#include<string.h>
void h(char *n,int l);
int main(void)
{
	char n[100];
	int l;

	scanf("%s",n);
	l=strlen(n);
	printf("%s,%d\n",n,l);
	n[l]='\0';
	h(n,l);
	return 0;
}
void h(char *n,int l)
{
	char t[100];

	int i;
	for(i=0;i<l;i++)
	{
		t[l-i-1]=n[i];
	}
	t[l]='\0';
	if(strcmp(t,n)==0)
	{
		printf("%s\n",n);
	}	
}
