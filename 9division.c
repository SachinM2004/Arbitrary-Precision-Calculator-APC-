#include "2head.h"

int division(Dlist *head1,Dlist *head2,Dlist **res_head,Dlist *tail1,Dlist *tail2,Dlist **res_tail)
{
    if (compare(head1, head2) < 0)
    {
        insert(res_head, res_tail, 0);
        return SUCCESS;
    }

    Dlist *current_head = NULL;
    Dlist *current_tail = NULL;

    while (head1)
    {
        insert(&current_head, &current_tail, head1->data);

        remove_leading_zero(&current_head);
        current_tail = get_tail(current_head);

        int count = 0;

        while (current_head && compare(current_head, head2) >= 0)
        {
            Dlist *new_head = NULL;
            Dlist *new_tail = NULL;

            subtract_positive(current_head,current_tail,head2,tail2,&new_head,&new_tail);

            free_list(&current_head);

            current_head = new_head;
            current_tail = new_tail;

            count++;
        }

        insert(res_head, res_tail, count);

        head1 = head1->next;
    }

    remove_leading_zero(res_head);

    free_list(&current_head);

    return SUCCESS;
}

void remove_leading_zero(Dlist **head)
{
    while (*head && (*head)->next && (*head)->data == 0)
    {
        Dlist *temp = *head;
        *head = (*head)->next;
        (*head)->prev = NULL;
        free(temp);
    }
}

Dlist *get_tail(Dlist *head)
{
    while (head && head->next)
    {
        head = head->next;
    }
    return head;
}









