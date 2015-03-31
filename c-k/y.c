#include<stdio.h>
int main(void)
{
	int year,month,day,y_time;
	
	scanf("%d%d%d",&year,&month,&day);
	y_time=day<<11|month<<7|year;
	printf("%d\n",y_time);
	printf("%d %d %d",y_time>>11,((y_time<<5)>>12),((y_time<<9)>>9));
	return 0;
}
