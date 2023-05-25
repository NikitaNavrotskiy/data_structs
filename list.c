#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "unistd.h"


node * __create_node(void * data, node * next, node * prev)
{
    node * tmp = (node *)malloc(sizeof(node));

    if(tmp == NULL)
        return NULL;

    tmp->data = data;
    tmp->__next = next;
    tmp->__prev = prev;

    return tmp;
}


void __remove_node(node * nd)
{
    free(nd);
}





list * create_list()
{
    list * tmp = (list *)malloc(sizeof(list));
    tmp->__head = NULL;
    tmp->__tail = NULL;

    return tmp;
}


void push_back(list * lst, void * data)
{
    node * tmp = lst->__tail;

    lst->__tail = __create_node(data, NULL, tmp);

    if(lst->__head == NULL)
        lst->__head = lst->__tail;
    else
        tmp->__next = lst->__tail;
}


void push_front(list * lst, void * data)
{
    node * tmp = lst->__head;

    lst->__head = __create_node(data, tmp, NULL);
    
    if(lst->__tail == NULL)
        lst->__tail = lst->__head;
    else
        tmp->__prev = lst->__head;
}



void pop_front(list * lst)
{
    if(lst->__head == NULL)
        return;

    node * cur = lst->__head;

    lst->__head = cur->__next;

    if(lst->__head!=NULL)
        lst->__head->__prev = NULL;
    else
        lst->__tail = NULL;

    __remove_node(cur);
}


void pop_back(list * lst)
{
    if(lst->__tail == NULL)
        return;

    node * cur = lst->__tail;

    lst->__tail = cur->__prev;

    if(lst->__tail!=NULL)
        lst->__tail->__next = NULL;
    else
        lst->__head = NULL;

    __remove_node(cur);
}


void print_d(list * lst)
{
    node * cur = lst->__head;
    while(cur!=NULL)
    {
        printf("%d ", *(int *)cur->data);
        cur = cur->__next;
    }
    printf("\n");
}


void printr_d(list * lst)
{
    node * cur = lst->__tail;
    while(cur!=NULL)
    {
        printf("%d ", *(int *)cur->data);
        cur = cur->__prev;
    }
    printf("\n");
}


node * front(list * lst)
{
    node * cur = lst->__head;
    return  cur;
}


node * back(list * lst)
{
    node * cur = lst->__tail;
    return  cur;
}


int count_list(list * lst)
{
    int count = 0;
    node * cur = lst->__tail;
    while(cur!=NULL)
    {
        count++;
        cur = cur->__prev;
    }

    return count;
}


void remove_list(list * lst)
{
    if(lst->__head != NULL)
    {
        node * cur = lst->__head, * cur2 = lst->__head->__next;
        while(cur2!=NULL)
        {
            __remove_node(cur);
            cur = cur2;
            cur2 = cur2->__next;
        }

        __remove_node(cur);
    }

    free(lst);
}


void clear_list(list * lst)
{
    if(lst->__head != NULL)
    {
        node * cur = lst->__head, * cur2 = lst->__head->__next;
        while(cur2!=NULL)
        {
            __remove_node(cur);
            cur = cur2;
            cur2 = cur2->__next;
        }

        __remove_node(cur);
    }

    lst->__head = NULL;
    lst->__tail = NULL;
}


int empty_list(list * lst)
{
    return lst->__head == NULL;
}


int main()
{
    int a = 5, b = 6, c = 7, d = 4;
    int *pa = &a, *pb = &b, *pc = &c, *pd = &d;
    list * l = create_list();
    push_back(l, (void *)pa);
    push_back(l, (void *)pb);
    push_back(l, (void*)pc);
    push_front(l, (void*)pd);
    pop_back(l);
    pop_back(l);
    pop_back(l);
    pop_back(l);
    printf("%d", count_list(l));
    print_d(l);
    printr_d(l);
    printf("%d", empty_list(l));
    remove_list(l);
    return 0;
}



