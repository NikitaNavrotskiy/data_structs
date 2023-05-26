#include "stack.h"


__node_s * __create_node_s(void * data, __node_s * __next)
{
    __node_s * tmp = (__node_s *)malloc(sizeof(__node_s));

    tmp->data = data;
    tmp->__next = __next;

    return tmp;
}

void __remove_node_s(__node_s * nd)
{
    free(nd);
}

stack * create_stack()
{
    stack * st = (stack *)malloc(sizeof(stack));

    st->__head = NULL;

    return st;
}


void * top_s(stack * s)
{
    if(s->__head == NULL)
        return NULL;
    return s->__head->data;
}


void push_s(stack * s, void * data)
{
    s->__head = __create_node_s(data, s->__head);
}


void pop_s(stack * s)
{
    if(s->__head == NULL)
        return;

    if(s->__head->__next == NULL)
    {
        __remove_node_s(s->__head);
        s->__head = NULL;
        return;
    }

    __node_s * tmp = s->__head;
    s->__head = tmp->__next;

    __remove_node_s(tmp);
}


int empty_s(stack * s)
{
    return s->__head == NULL;
}

int size_s(stack * s)
{
    int count = 0;
    __node_s * cur = s->__head;

    while(cur!=NULL)
    {
        count++;
        cur = cur->__next;
    }

    return count;
}

void remove_stack(stack * s)
{
    while(!empty_s(s))
        pop_s(s);

    free(s);
}


void clear_stack(stack * s)
{
    while(!empty_s(s))
        pop_s(s); 
}


void print_d_s(stack * s)
{
    __node_s * cur = s->__head;

    while(cur!=NULL)
    {
        printf("%d ", *(int*)cur->data);
        cur = cur->__next;
    }
    printf("\n");
}


int main()
{   
    int a = 1, b = 2, c =3, d = 4;
    int * pa = &a;
    int * pb = &b;
    int * pc = &c;
    int * pd = &d;
    stack * st = create_stack();
    push_s(st, (void *)pa);
    push_s(st, (void*)pb);
    push_s(st, (void *)pc);
    push_s(st, (void*)pd);
    print_d_s(st);
    pop_s(st);
    print_d_s(st);
    printf("%d", *(int*)top_s(st));
    clear_stack(st);
    remove_stack(st);

    return 0;
}