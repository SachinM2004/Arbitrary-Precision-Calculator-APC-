#include"2head.h"

int compare(Dlist *head1, Dlist *head2)
{
    // Remove leading zeros
    while (head1 && head1->data == 0 && head1->next)
    {
        head1 = head1->next;
    }

    while (head2 && head2->data == 0 && head2->next)
    {
        head2 = head2->next;
    }

    int l1 = 0, l2 = 0;
    Dlist *temp;

    temp = head1;
    while (temp)
    {
        l1++;
        temp = temp->next;
    }

    temp = head2;
    while (temp)
    {
        l2++;
        temp = temp->next;
    }

    if (l1 > l2)
        return 1;
    else if (l2 > l1)
        return -1;

    while (head1 && head2)
    {
        if (head1->data > head2->data)
            return 1;

        if (head1->data < head2->data)
            return -1;

        head1 = head1->next;
        head2 = head2->next;
    }

    return 0;
}