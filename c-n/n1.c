#include<stdio.h>
int main(void)
{
	int x,n,s;
	
	printf("Enter two intergers:\n");
	scanf("%d%d",&x,&n);
	s=8*sizeof(x);
	printf("%d\n",x>>n|x<<(s-n));
	
	return 0;
}
