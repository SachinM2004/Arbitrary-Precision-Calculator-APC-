#include "2head.h"


int substraction(Dlist *head1,Dlist *head2,Dlist** res_head,Dlist* tail1,Dlist* tail2,Dlist** res_tail)
{
    int  cmp = compare(head1,head2);

    if(cmp==0)
    {
        insert(res_head, res_tail, 0);
        return SUCCESS;
    }

    int borrow = 0;
    int sub;
    while(tail1 != NULL || tail2 != NULL)
    {
       
        int data1 = 0, data2 = 0;
    if(cmp == 1)
    {
        if (tail1)
        {
            data1 = tail1->data;
            tail1 = tail1->prev;
        }

        if (tail2)
        {
            data2 = tail2->data;
            tail2 = tail2->prev;
        }
    }
    else
    {
        if (tail1)
        {
            data2 = tail1->data;
            tail1 = tail1->prev;
        }

        if (tail2)
        {
            data1 = tail2->data;
            tail2 = tail2->prev;
        }

        
    }

        data1 = data1 - borrow;

        if(data1 < data2)
        {
            data1 += 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }

        
        sub = data1 - data2;

       
            Dlist* new = malloc(sizeof(Dlist));
            if(new==NULL) return FAILURE;

            (new)->data=sub;
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
