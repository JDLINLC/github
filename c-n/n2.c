#include<stdio.h>
#include<string.h>
int main(void)
{
	char a[100],b[100];
	int m,n;
	
	printf("Enter a string:\n");
	scanf("%s",a);
	printf("Enter an interger:\n");
	scanf("%d",&m);
	n=strlen(a)-m;
	strcpy(b,a+m);
	strcpy(b+n,a);
	*(b+strlen(a))='\0';
	printf("Output:\n%s\n",b);

	return 0;
}
