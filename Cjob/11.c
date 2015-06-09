#include<stdio.h>
#define MONTH 12
int main(void)
{
	int n,i,j;
	int year,month,day;
	int year_month1[MONTH]={31,29,31,30,31,30,31,31,30,31,30,31};
	int year_month2[MONTH]={31,28,31,30,31,30,31,31,30,31,30,31};

	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d",&year,&month,&day);
		if((year%4==0&&year%100!=0)||(year%400==0))
		{
			for(j=0;j<month-1;j++)
			{
				day +=year_month1[j];
			}
		}
		else
		{
			for(j=0;j<month-1;j++)
			{
				day +=year_month2[j];
			}
		}
		printf("%d\n",day);
	}

	return 0;
}
