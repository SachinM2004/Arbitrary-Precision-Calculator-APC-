#include "2head.h"

int multiplication(Dlist *head1, Dlist *head2,Dlist **res_head, Dlist *tail1,Dlist *tail2, Dlist **res_tail)
{
    *res_head = NULL;
    *res_tail = NULL;

    int shift = 0;

    while (tail2)
    {
        Dlist *partial_head = NULL;
        Dlist *partial_tail = NULL;

        int carry = 0;
        Dlist *temp1 = tail1;

        /* Multiply one digit of second number with first number */
        while (temp1)
        {
            int product = temp1->data * tail2->data + carry;

            carry = product / 10;

            /* Insert at FRONT */
            insert_first(&partial_head, &partial_tail, product % 10);

            temp1 = temp1->prev;
        }

        if (carry)
            insert_first(&partial_head, &partial_tail, carry);

        /* Append shift zeros */
        for (int i = 0; i < shift; i++)
            insert(&partial_head, &partial_tail, 0);

        /* First partial product */
        if (*res_head == NULL)
        {
            *res_head = partial_head;
            *res_tail = partial_tail;
        }
        else
        {
            Dlist *new_head = NULL;
            Dlist *new_tail = NULL;

            addition(*res_head,partial_head,&new_head,get_tail(*res_head),get_tail(partial_head),&new_tail);

            free_list(res_head);
            free_list(&partial_head);

            *res_head = new_head;
            *res_tail = new_tail;
        }

        shift++;
        tail2 = tail2->prev;
    }

    return SUCCESS;
}