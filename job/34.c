#include<stdio.h>

#define BALLVOL(r) (3.1415926*r*r*r*4/3)

int main (void)
{
	int start,end;

	scanf("%d%d",&start,&end);

	while(start>=0&&end>=0)
	{
		printf("radius    volume\n");
		for(;start<=end;start++)
		{
			printf("%d     %lf\n",start,BALLVOL(start));
		}
		putchar('\n');
		scanf("%d%d",&start,&end);
	}

	return 0;
}
