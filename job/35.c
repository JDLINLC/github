#include<stdio.h>

#define SWAP(x,y) (x=x+y,y=x-y,x=x-y)

int main(void)
{
	int n;
	int x,y;

	scanf("%d",&n);

	for(;n>0;n--)
	{
		scanf("%d%d",&x,&y);
		SWAP(x,y);
		printf("%d %d\n",x,y);
	}

	return 0;
}
