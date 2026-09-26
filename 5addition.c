#include "2head.h"

int addition(Dlist *head1,Dlist *head2,Dlist** res_head,Dlist* tail1,Dlist* tail2,Dlist** res_tail)
{
    int sum,carry=0;
    while(tail1 != NULL || tail2 != NULL ||carry)
    {
        int data1 = 0, data2 = 0;

        if (tail1 != NULL)
        {
            data1 = tail1->data;
            tail1 = tail1->prev;
        }

        if (tail2 != NULL)
        {
            data2 = tail2->data;
            tail2 = tail2->prev;
        }
        
        sum = data1 + data2 +carry;

        carry = sum / 10;
        int digit = sum % 10;

  

            Dlist* new = malloc(sizeof(Dlist));
            if(new==NULL) return FAILURE;

            (new)->data=digit;
            (new)->next = NULL;
            (new)->prev = NULL;


        if(*res_tail == NULL)
        {
            *res_head = *res_tail = new;
        }
        else
        {
            (new)->next=*res_head;
            (*res_head)->prev=new;
            *res_head = new;
        }
        
    }

    while (*res_head != *res_tail && (*res_head)->data == 0) 
    { 
        Dlist *temp = *res_head; 
        *res_head = (*res_head)->next; 
        (*res_head)->prev = NULL; 
        free(temp); 
    }

    return SUCCESS;
}


