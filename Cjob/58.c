#include<stdio.h>
struct Web{
    char short_name[19];
    char name[39];
    char URL[81];
};
int compare(struct Web a,struct Web b);
int main(void)
{
    int n,i,j;
    scanf("%d",&n);
    struct Web web[n],temp;
    for(i=0;i<n;i++)
        scanf("%s%s%s",web[i].short_name,web[i].name,web[i].URL);
    for(i=0;i<n;i++)
        printf("%-20s%-40s%s\n",web[i].short_name,web[i].name,web[i].URL);
    putchar('\n');
    for(i=0;i<n-1;i++)
        for(j=i;j<n;j++)
        {
            if(compare(web[i],web[j])>=0)
                temp=web[i],web[i]=web[j],web[j]=temp;
        }
    for(i=0;i<n;i++)
        printf("%-20s%-40s%s\n",web[i].short_name,web[i].name,web[i].URL);

    return 0;
}
int compare(struct Web a,struct Web b)
{
    int k=0;
    while(a.short_name[k]==b.short_name[k]&&a.short_name[k])
        k++;
    return a.short_name[k]-b.short_name[k];
}
