#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define TSIZE 45
struct film{
	char title[TSIZE];
	int rating;
	struct film *next;
};
int main(void)
{
	char input[TSIZE];
	struct film *head=NULL;
	struct film *prev,*current;

	puts("Enter the movie title(empty line to quit):");
	while(gets(input)!=NULL&&input[0]!='\0')
	{
		current=(struct film*)malloc(sizeof(struct film));
		if(head==NULL)
			head=current;
		else
			prev->next=current;
		strcpy(current->title,input);
		puts("Enter the rating:");
		scanf("%d",&current->rating);
		while(getchar()!='\n')
			continue;
		puts("Enter another movie title(empty line to quit):");
		prev=current;
	}	
	
	if(head==NULL)
		printf("No movie data.\n");
	else
		printf("Here is the movie list:\n");
	current=head;
	while(current!=NULL)
	{
		printf("Movie:%s Rating:%d\n",current->title,current->rating);
		current=current->next;
	}
	
	current=head;
	while(current!=NULL)
	{
		free(current);
		current=current->next;
	}
	printf("Bye.\n");

	return 0;
}
