#include<stdio.h>
int main(void)
{
	short int x;
	int n,i=0;

	scanf("%d",&n);
	while(i<n)
	{
		scanf("%hd",&x);
		printf("%c,%c\n",(x>>8&0xff),x&0xff);
		i++;
	}
	return 0;
}
