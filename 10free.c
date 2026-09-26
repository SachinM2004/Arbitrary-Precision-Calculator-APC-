#include "2head.h"

void free_list(Dlist **head)
{
    Dlist *temp;

    while (*head)
    {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}