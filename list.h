#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 45
struct film{
    char title[MAX];
    int rating;
    struct film *next;
};
void create_list(struct film *head);
void show_list(struct film *head);
void free_list(struct film *head);


void create_list(struct film *head)
{
    struct film *current,*prev;
    char input[MAX];

    printf("Enter the movie title(empty line to quit):\n");
    while(fgets(input,sizeof(input),stdin)!=NULL&&input[0]!='\n')
    {
        current=(struct film *)malloc(sizeof(struct film));
        if(head==NULL)
        {
            head=current;
            printf("hello\n");
        }
        else
            prev->next=current;
        strcpy(current->title,input);
        printf("Enter the rating:\n");
        scanf("%d",&current->rating);
        while(getchar()!='\n')
            continue;
        printf("Enter next movie title(empty line to quit):\n");
        prev=current;
    }
}
void show_list(struct film *head)
{
    struct film *current;
    if(head==NULL)
        printf("No data entered.\n");
    else
        printf("Here is the movie list:\n");
    current=head;
    while(current!=NULL)
    {
        printf("Movie:%s Rating:%d\n",current->title,current->rating);
        current=current->next;
    }
}
void free_list(struct film *head)
{
    struct film *current,*prev;
    current=head;
    while(current!=NULL)
    {
            prev=current;
            free(current);
            current=prev->next;
    }
    printf("Bye!\n");
}
