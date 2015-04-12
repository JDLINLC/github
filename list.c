#include<stdio.h>
#include "list.h"
int main(void)
{
        struct film *head=NULL;

        create_list(head);
        printf("%d\n",head);
        show_list(head);
        free_list(head);

        return 0;
}
