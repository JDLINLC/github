#include<stdio.h>
#include<string.h>
void reverse(char *a,int start,int end);
void turnleft(char *a,int i,int n);
int main(void)
{
	char a[100];
	int i,n;

	printf("Enter a string:\n");
	scanf("%s",a);
	n=strlen(a);
	printf("Enter an interger:\n");
	scanf("%d",&i);
	turnleft(a,i,n);
	printf("%s\n",a);
	
	return 0;
}


void reserve(char *a,int start,int end)
{
	int temp;

	for(start;start<end;start++,end--)
	{
		temp=a[start];
		a[start]=a[end];
		a[end]=temp;
	}
}
void turnleft(char *a,int i,int n)
{
	int left;
	
	left=i%n;
	if(left!=0)
	{
		reserve(a,0,n-1);
		reserve(a,0,left-1);
		reserve(a,left,n-1);
	}
}	
