#define MAX 45
struct film{
	char title[MAX];
	int rating;
	struct film *next;
};
void create_list(struct film *head,struct film *tail);
void show_list(struct film *head);
int count_list(struct film *head);
void search_list(struct film *head);
void insert_list(struct film *tail);
void delete_list(struct film *head,char title);
void concatenate_list(struct film *head,struct film *head1);
void sort_list(struct film *head);

void create_list(struct film *head,struct film *tail)
{
	char input[MAX];
	struct film *current,*prev;

	printf("Enter the movie title(empty line to quit):\n");
	while(gets(input)!=NULL&&input[0]!='\0')
	{
		current=(struct film *)malloc(sizeof(struct film));
		if(head==NULL)
			head=current;
		else
			prev->next=current;
		strcpy(current->title,input);
		printf("Enter the movie rating:\n");
		scanf("%d",&current->rating);
		while(getchar()!='\n')
			continue;
		printf("Enter another movie title(empty line to quit):\n");
		prev=current;
	}
	tail=current;
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
		printf("Movie:%s   Rating:%d\n",current->title,current->rating);
		current=current->next;		
	}
}

int count_list(struct film *head)
{
	int num=0;

	while(head)
	{
		head=head->next;
		num +=1;
	}
	printf("There are %d movie have been save.\n",num);
	
	return num;
}

void search_list(struct film *head)
{
	struct film *current;
	char input[MAX];
	int i=0,j=0,k=0;
	int l,s;
	
	printf("Enter the movie you want to search:\n");
	gets(input);
	l=strlen(input);
	current=head;
	while(current!=NULL)
	{
		s=strlen(current->title);
		if(s==l)
		{
			for(i=0;i<l;i++)
			{
				if(current->title[i]==input[i])
					j +=1;
			}
			if(j==l)
			{
				printf("Movie:%s Rating:%d\n",current->title,current->rating);
				k +=1;
			}
		}
		current=current->next;	
	}
	printf("Totally %c movie can be found.",k);
}

void insert_list(struct film *tail)
{
	struct film *psave;
	char input[MAX];

	psave=(struct film *)malloc(sizeof(struct film));
	printf("Enter the movie title:\n");
	if(gets(input)!=NULL&&input[0]!='\0')
	{
		psave=tail->next;
		strcpy(psave->title,input);
		printf("Enter the movie rating:\n");
		scanf("%d",&psave->rating);
	}
	else
		printf("Worry.\n");
}

void delect_list(struct film *head)
{
	struct film *current,*prev;
	struct film *scurrent,*sprev;
	char input[MAX];
	int i=0,j=0;
	int l,s;

	printf("Enter the movie title you want to delect:\n");
	gets(input);
	l=strlen(input);
	current=head;
	prev=current;
	while(current!=NULL)
	{
		s=strlen(current->title);
		if(l==s)
		{
			for(i=0;i<l;i++)
			{
				if(current->title[i]==input[i])
				{
					j++;
				}
			}
			if(j==l)
			{
				prev->next=current->next;
				free(current);
				current=prev;
			}
		}
		prev=current;
		current=current->next;	
	}
}


