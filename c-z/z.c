#include<stdio.h>
int main(void)
{
	int n,i=0,j;
	char s[100],r[100];

	printf("Enter an interger:\n");
	scanf("%d",&n);
	s[i]=(n%10)+48;
	while(n/10!=0)
	{
		i +=1;
		n /=10;
		s[i]=(n%10)+48;
	}
	s[i+1]='\0';
	printf("%s\n",s);
	for(j=0;j<=i;j++)
	{
		r[i-j]=s[j];
	}
	printf("%s\n",r);
	return 0;
}
