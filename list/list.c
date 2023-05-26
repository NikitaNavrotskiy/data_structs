#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "unistd.h"


__node * __create_node_l(void * data, __node * next, __node * prev)
{
    __node * tmp = (__node *)malloc(sizeof(__node));

    if(tmp == NULL)
        return NULL;

    tmp->data = data;
    tmp->__next = next;
    tmp->__prev = prev;

    return tmp;
}


void __remove_node_l(__node * nd)
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


void push_back_l(list * lst, void * data)
{
    __node * tmp = lst->__tail;

    lst->__tail = __create_node_l(data, NULL, tmp);

    if(lst->__head == NULL)
        lst->__head = lst->__tail;
    else
        tmp->__next = lst->__tail;
}


void push_front_l(list * lst, void * data)
{
    __node * tmp = lst->__head;

    lst->__head = __create_node_l(data, tmp, NULL);
    
    if(lst->__tail == NULL)
        lst->__tail = lst->__head;
    else
        tmp->__prev = lst->__head;
}



void pop_front_l(list * lst)
{
    if(lst->__head == NULL)
        return;

    __node * cur = lst->__head;

    lst->__head = cur->__next;

    if(lst->__head!=NULL)
        lst->__head->__prev = NULL;
    else
        lst->__tail = NULL;

    __remove_node_l(cur);
}


void pop_back_l(list * lst)
{
    if(lst->__tail == NULL)
        return;

    __node * cur = lst->__tail;

    lst->__tail = cur->__prev;

    if(lst->__tail!=NULL)
        lst->__tail->__next = NULL;
    else
        lst->__head = NULL;

    __remove_node_l(cur);
}


void print_d_l(list * lst)
{
    __node * cur = lst->__head;
    while(cur!=NULL)
    {
        printf("%d ", *(int *)cur->data);
        cur = cur->__next;
    }
    printf("\n");
}


void printr_d_l(list * lst)
{
    __node * cur = lst->__tail;
    while(cur!=NULL)
    {
        printf("%d ", *(int *)cur->data);
        cur = cur->__prev;
    }
    printf("\n");
}


void * front_l(list * lst)
{
    __node * cur = lst->__head;
    return  cur->data;
}


void * back_l(list * lst)
{
    __node * cur = lst->__tail;
    return  cur->data;
}


int count_list(list * lst)
{
    int count = 0;
    __node * cur = lst->__tail;
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
        __node * cur = lst->__head, * cur2 = lst->__head->__next;
        while(cur2!=NULL)
        {
            __remove_node_l(cur);
            cur = cur2;
            cur2 = cur2->__next;
        }

        __remove_node_l(cur);
    }

    free(lst);
}


void clear_list(list * lst)
{
    if(lst->__head != NULL)
    {
        __node * cur = lst->__head, * cur2 = lst->__head->__next;
        while(cur2!=NULL)
        {
            __remove_node_l(cur);
            cur = cur2;
            cur2 = cur2->__next;
        }

        __remove_node_l(cur);
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
    push_back_l(l, (void *)pa);
    push_back_l(l, (void *)pb);
    push_back_l(l, (void*)pc);
    push_front_l(l, (void*)pd);
    pop_back_l(l);
    pop_back_l(l);
    pop_back_l(l);
    pop_back_l(l);
    printf("%d", count_list(l));
    print_d_l(l);
    printr_d_l(l);
    printf("%d", empty_list(l));
    remove_list(l);
    return 0;
}



