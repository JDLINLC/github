/*使用结构链表*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define TSIZE 45
struct film{
	struct film *prev;
	char title[TSIZE];
	int rating;
	struct film *next;
};
int main(void)
{
	struct film *head=NULL;
	struct film *current,*prev;
	struct film *psave,*csave;
	char input[TSIZE];
	
	/*收集并存储信息*/
	puts("Enter the movie title(empty line to quit):");
	while(gets(input)!=NULL&&input[0]!='\0')
	{
		current=(struct film *)malloc(sizeof(struct film));
		if(head==NULL)
			head=current;
		else
		{
			current->prev=prev;
			prev->next=current;
		}
		strcpy(current->title,input);
		puts("Enter the movie rating:");
		scanf("%d",&current->rating);
		while(getchar()!='\n')
			continue;
		puts("Enter anther movie title(empty line to quit):");
		prev=current;
	}

	/*给出电影列表*/
	if(head==NULL)
		puts("No data entered.");
	else
		puts("Here is the movie list:");
	current=head;
	while(current!=NULL)
	{
		printf("Movie:%s Rating:%d\n",current->title,current->rating);
		current=current->next;
	}

	/*遍历链表*/
	printf("Enter the movie title you want to fine(empty line to qiut):\n");
	while(gets(input)!=NULL&&input[0]!='\0')
	{
		int l,i,j,k=0;
		l=strlen(input);
		if(head==NULL)
			printf("No movie.\n");
		else
		{
			current=head;
			while(current!=NULL)
			{
				j=strlen(current->title);
				for(i=0;i<l;i++)
				{
					if(input[i]==current->title[i])
						continue;
					else
						break;
				}
				if(i==j)
				{
					k +=1;	
					printf("Movie:%s Rating:%d\n",current->title,current->rating);
					csave=current;
					psave=current->prev;
				}
				current=current->next;
			}
			printf("There are %d movie can be found.\n",k);	
		}
		puts("Enter another movie title to fine(empty line to quit):");
	}

	char a;
	printf("Do you want to remove this movie from your movie list?(Y\\N):\n");
	scanf("%c",&a);
	if(a=='Y'||a=='y')
	{
		psave->next=csave->next;
		printf("Movie:%s have been removed.\n",csave->title);
		free(csave);
	}
	else if(a=='N'||a=='n')
		printf("No change.\n");
	else
		printf("Your enter is wrong.\n"); 

	/*释放所分配的内存*/
	current=head;
	while(current!=NULL)
	{
		free(current);
		current=current->next;
	}
	printf("Bye\n");
		
	return 0;
}
