#include"2head.h"

void print_list(Dlist *head)
{

if (head == NULL)
{
    printf("List Empty\n");
    return;
}
    Dlist *temp = head;
    while (temp)
    {
        printf("%d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


