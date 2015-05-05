#include<stdio.h>
#define SWAP(x,y) (x=x+y,y=x-y,x=x-y)
#define BALLVOL(r) (3.1415926*r*r*r*4/3)

int main (void)
{
	int start,end;

	scanf("%d%d",&start,&end);

	while(start>=0&&end>=0)
	{
		if(start>end)
		{
			SWAP(start,end);
		}
		printf("radius\tvolume\n");
		for(;start<=end;start++)
		{
			printf("%d\t%lf\n",start,BALLVOL(start));
		}
		putchar('\n');
		scanf("%d%d",&start,&end);
	}

	return 0;
}
