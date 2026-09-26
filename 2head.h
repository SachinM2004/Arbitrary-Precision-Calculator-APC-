#ifndef HEAD_H
#define HEAD_H

#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

#define SUCCESS 0
#define FAILURE -1

typedef struct node
{
    int data;
    struct node* prev;
    struct node* next;
}Dlist;

int insert(Dlist** head,Dlist** tail,int data);
void print_list(Dlist *head);
int isZero(Dlist *head);
Dlist *get_tail(Dlist *head);
void remove_leading_zero(Dlist **head);

int insert_first(Dlist **head, Dlist **tail, int data);
int addition(Dlist *head1,Dlist *head2,Dlist** res_head,Dlist* tail1,Dlist* tail2,Dlist** res_tail);
int substraction(Dlist *head1,Dlist *head2,Dlist** res_head,Dlist* tail1,Dlist* tail2,Dlist** res_tail);
int compare(Dlist* head1,Dlist* head2);
int multiplication(Dlist *head1,Dlist *head2,Dlist** res_head,Dlist* tail1,Dlist* tail2,Dlist** res_tail);
int division(Dlist *head1,Dlist *head2,Dlist** res_head,Dlist* tail1,Dlist* tail2,Dlist** res_tail);
int subtract_positive(Dlist *head1,Dlist *tail1,Dlist *head2,Dlist *tail2,Dlist **res_head,Dlist **res_tail);
void free_list(Dlist **head);

#endif




