
#include "2head.h"
#include <ctype.h>
//cd DSA/project/

int main(int argc, char* argv[])
{
     if (argc != 4)
    {
        printf("Usage: ./a.out <number1> <operator> <number2>\n");
        return 1;
    }


    Dlist* head1=NULL;
    Dlist* tail1=NULL;
    Dlist* head2=NULL;
    Dlist* res_head=NULL;
    Dlist* tail2=NULL;
    Dlist* res_tail=NULL;

    
        char *num1 = argv[1];
        char *num2 = argv[3];

        int sign1 = 1, sign2 = 1;

        if (num1[0] == '-')
        {
            sign1 = -1;
            num1++;         
        }

        if (num2[0] == '-')
        {
            sign2 = -1;
            num2++;          
        }

    int i=0;
    while (num1[i])
    {
        if (!isdigit(num1[i]))
        {
            printf("Invalid Input\n");
            return 1;
        }

        insert(&head1, &tail1, num1[i] - '0');
        i++;
    }
    print_list(head1);
  


    i=0;
    while (num2[i])
    {
        if (!isdigit(num2[i]))
        {
            printf("Invalid Input\n");
            return 1;
        }

        insert(&head2, &tail2,num2[i] - '0');
        i++;
    }
    print_list(head2);


    //checking devidend and diviser are 0
if (argv[2][0] == '/' && isZero(head2))
{
    printf("Error: Division by zero\n");
    free_list(&head1);
    free_list(&head2);
    return 0;
}

   
if(argv[2][0] == '+' || argv[2][0] == '-' || argv[2][0] == '*' || argv[2][0] == '/')
{
    switch(argv[2][0])
    {
        case '+':
        {
            res_head = NULL;
            res_tail = NULL;
            if(sign1==sign2)
            {
                if(addition(head1,head2,&res_head,tail1,tail2,&res_tail)==FAILURE)
                {
                    printf("not possible");
                }
                if(sign1==-1)
                printf("-");
            }
            else
            {
                if(compare(head1,head2)>=0)
                {
                    substraction(head1,head2,&res_head,tail1,tail2,&res_tail);

                    if(sign1 == -1)
                    printf("-");

                }
                else
                {
                    substraction(head2,head1,&res_head,tail1,tail2,&res_tail);

                    if(sign2 == -1)
                    printf("-");
                }
            }
            
            print_list(res_head);
        }
        break;

        case '-':
        {
            res_head = NULL;
            res_tail = NULL;
             if(sign1 == sign2)
            {
                int cmp = compare(head1, head2);

                if(sign1 == 1)      
                {
                    if(cmp >= 0)
                    {
                        substraction(head1, head2,&res_head, tail1, tail2, &res_tail);
                    }
                    else
                    {
                        printf("-");
                        substraction(head2, head1,&res_head, tail2, tail1, &res_tail);
                    }
                }
                else                // -a - (-b)
                {
                    if(cmp >= 0)
                    {
                        printf("-");
                        substraction(head1, head2,&res_head, tail1, tail2, &res_tail);
                    }
                    else
                    {
                        substraction(head2, head1,&res_head, tail2, tail1, &res_tail);
                    }
                }
            }
            else
            {
                addition(head1, head2,&res_head, tail1, tail2, &res_tail);

                if(sign1 == -1)     // (-a)-(+b)
                    printf("-");
            }

            print_list(res_head);
        }
        break;

        case '*':
        {
            res_head = NULL;
            res_tail = NULL;

            if (multiplication(head1, head2,&res_head,tail1, tail2,&res_tail)== FAILURE)
            {
                printf("not possible");
            }
            else
            {
                /* Avoid printing -0 */
                if (!(res_head->data == 0 && res_head->next == NULL))
                {
                    if (sign1 * sign2 == -1)
                    {
                        printf("-");
                    }
                }

                print_list(res_head);
            }
        }
        break;

        
        
        case '/':
        {
            res_head = NULL;
            res_tail = NULL;

            if (division(head1, head2,&res_head,tail1, tail2,&res_tail) == FAILURE)
            {
                printf("not possible");
            }
            else
            {
                /* Avoid printing -0 */
                if (!(res_head->data == 0 && res_head->next == NULL))
                {
                    if (sign1 * sign2 == -1)
                    {
                        printf("-");
                    }
                }

                print_list(res_head);
            }
        }
        break;

        default:
            printf("Invalid oprator\n");
            return 0;
    }

}

free_list(&head1);
free_list(&head2);
free_list(&res_head);

    return 0;
 
}




int isZero(Dlist *head)
{
    while (head)
    {
        if (head->data != 0)
            return 0;

        head = head->next;
    }

    return 1;
}