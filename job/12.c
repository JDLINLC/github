#include<stdio.h>
int main(void)
{
	int n,i;
	double a,b,x;
	char ch;

	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lf%lf",&a,&b);
		while((ch=getchar())=='\0'&&ch=='\n')
		  continue;
		ch=getchar();
		switch(ch)
		{
			case '+':
				x=a+b;
				printf("%lf+%lf=%lf\n",a,b,x);
				break;
			case '-':
				x=a-b;
				printf("%lf-%lf=%lf\n",a,b,x);
				break;
			case '*':
				x=a*b;
				printf("%lf*%lf=%lf\n",a,b,x);
				break;
			case '/':
				if(b!=0)
				{
				  x=a/b;
				  printf("%lf/%lf=%lf\n",a,b,x);
				}
				else
				  printf("Error!No result.\n");
				break;
			default:
				printf("Error!No result.\n");
				break;
		}
	}

	return 0;
}
