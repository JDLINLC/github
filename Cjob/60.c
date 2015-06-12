#include<stdio.h>
#include<stdlib.h>
enum {undeleted,deleted};              /*定义状态常量*/
typedef struct input_ch{
	char ch;
	struct input_ch *next;
}string;								/*定义结构体并用typedef定义结构名为string*/						
int main(void)
{
	int state;
	char c;
	string *head,*current,*prior,*find,*insert;
	head=NULL;

	/*初始化链表*/
	while((c=getchar())!='\n')
	{
		if(head==NULL)
		{
			head=(string *)malloc(sizeof(string));
			current=head;
		}
		current->next=(string *)malloc(sizeof(string));
		current->ch=c;
		prior=current;
		current=current->next;
	}
	prior->next=NULL;

	/*遍历链表并输出链表*/
	current=head;
	while(current)
	{
		printf("%c",current->ch);
		current=current->next;
	}
	printf("\n");

	/*对链表进行操作*/
	while((c=getchar())!='\n')
	{
		state=undeleted;
		current=head;
		prior=current;
		/*判断是否存在相同的字符，若有则删除节点并将状态改为deleted*/
		while(current)
		{
			if(current->ch==c)
			{
				if(current==head)
				{
					head=current->next;
				}
				prior->next=current->next;
				state=deleted;
				free(current);
				break;
			}
			else
			{
				prior=current;
				current=current->next;
			}
		}
		/*判断状态是否为undeleted,是的话就进行插入操作*/
		if(state==undeleted)
		{
			current=head;
			prior=current;
			find=current;
			while(current)
			{
				if((current->ch-c)<(prior->ch-c))
				{
					find=current;
				}
				current=current->next;
			}
			insert=(string *)malloc(sizeof(string));
			insert->ch=c;
			insert->next=find->next;
			find->next=insert;
		}
		/*遍历链表并将链表输出*/
		current=head;
		while(current)
		{
			printf("%c",current->ch);
			current=current->next;
		}
		printf("\n");
	}

	return 0;
}
