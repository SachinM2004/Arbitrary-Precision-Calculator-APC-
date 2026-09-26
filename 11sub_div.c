#include "2head.h"

int subtract_positive(Dlist *head1, Dlist *tail1,Dlist *head2, Dlist *tail2, Dlist **res_head, Dlist **res_tail)
{
    int borrow = 0;

    while (tail1 || tail2)
    {
        int d1 = 0, d2 = 0;

        if (tail1)
        {
            d1 = tail1->data;
            tail1 = tail1->prev;
        }

        if (tail2)
        {
            d2 = tail2->data;
            tail2 = tail2->prev;
        }

        d1 -= borrow;

        if (d1 < d2)
        {
            d1 += 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }

        Dlist *new = malloc(sizeof(Dlist));
        if (new == NULL)
            return FAILURE;

        new->data = d1 - d2;
        new->prev = NULL;
        new->next = *res_head;

        if (*res_head)
            (*res_head)->prev = new;
        else
            *res_tail = new;

        *res_head = new;
    }

    remove_leading_zero(res_head);

    return SUCCESS;
}