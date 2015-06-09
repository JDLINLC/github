#include<stdio.h>
struct student{
    int num;
    char name[19];
    double score;
};
int main(void)
{
    int N,i;
    scanf("%d",&N);
    struct student student[3],*p=student;
    for(;N>0;N--)
    {
        for(i=0;i<3;i++)
            scanf("%d%s%lf",&student[i].num,student[i].name,&student[i].score);
        for(i=0;i<3;i++)
            printf("%d\t%-20s%lf\n",student[i].num,student[i].name,student[i].score);
        for(i=0;i<3;i++)
            printf("%d\t%-20s%lf\n",(*(p+i)).num,(*(p+i)).name,(*(p+i)).score);
    }
    return 0;
}
