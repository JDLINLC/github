#include<stdio.h>
struct data{
    int year;
    int month;
    int day;
};
int main(void)
{
    int N,i,days;
    int month_day[12]={31,29,31,30,31,30,31,31,30,31,30,31};
    scanf("%d",&N);
    for(;N>0;N--)
    {
        struct data data;
        scanf("%d%d%d",&data.year,&data.month,&data.day);
        days=data.day;
        if((!(data.year%4)&&(data.year%100))||!(data.year%400))
        {
            month_day[1]=29;
            for(i=0;i<data.month-1;i++)
            {
                days += month_day[i];
            }
        }
        else
        {
            month_day[1]=28;
            for(i=0;i<data.month-1;i++)
            {
                days += month_day[i];
            }
        }
        printf("%d\n",days);
    }

    return 0;
}
