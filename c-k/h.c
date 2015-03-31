#include<stdio.h>
#include<string.h>
void h(char *n,int l);
int main(void)
{
	char n[10000];
	int a,b,c,l;
	int i=0;

	printf("Enter two number:\n");
	while(scanf("%d%d",&a,&b)&&a<=b)
	{
		for(a;a<=b;a++)
		{
			c=a%10;
			n[i]=c;
			while((a=(a/10))!=0)
			{
				i +=1;
				c=a%10;
				n[i]=c;
			}
			l=strlen(n);
			h(n,l);			
		}
	}

	return 0;
}
void h(char *n,int l)
{
	int i=0,x=0;
	int k=l/2;

	for(i;i<l;i++,l--)
	{
		if(n[i]==n[l])
			x++;	
	}
	if(x==k)
		printf("%s",n);
}

