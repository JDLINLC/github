#include<stdio.h>
#include<stdlib.h>
struct ch_string{
	char ch;
	struct ch_string *next;
};

void alloc_input(char *s2);

int main(void)
{
	char c,*pc,*p_start;
	int i=0;
	struct ch_string head,*current,*p;
	head.next=NULL;
	current=&head;

	while((c=getchar())!=EOF)
	{
		current->ch=c;
		current->next=(struct ch_string *)malloc(sizeof(struct ch_string));
		current=current->next;
	}
	current->next=NULL;

	p=&head;
	while(p)
	{
		printf("%c",p->ch);
		p=p->next;
		i++;
	}
	printf("\n\n");

	pc=(char *)malloc(i*sizeof(char));
	p_start=pc;
	p=&head;
	while(p)
	{
		*pc=p->ch;
		pc++;
		p=p->next;
	}
	printf("%s\n",p_start);

	return 0;
}
