#include<stdio.h>
#include "list.h"
int main(void)
{
	struct film *head=NULL;
	struct film *tail;

	create_list(head,tail);
	show_list(head);
	count_list(head);
	search_list(head);
	insert_list(tail);
	show_list(head);
	count_list(head);
	delect_list(head);
	show_list(head);
	count_list(head);
	printf("Bye!");

	return 0;
}
