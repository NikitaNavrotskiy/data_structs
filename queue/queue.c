#include "queue.h"



__node_q * __create_node_q(void * data, __node_q * __next)
{
    __node_q * tmp = (__node_q *)malloc(sizeof(__node_q));

    tmp->data = data;
    tmp->__next = __next;

    return tmp;
}


void __remove_node_q(__node_q * nd)
{
    free(nd);
}


queue * create_queue()
{
    queue * tmp = (queue *)malloc(sizeof(queue));

    tmp->__head = NULL;
    tmp->__tail = NULL;
}


void * front_q(queue * q)
{
    return q->__head->data;
}


void * back_q(queue * q)
{
    return q->__tail->data;
}


void push_q(queue * q, void * data)
{
    q->__tail = __create_node_q(data, q->__tail);

    if(q->__head == NULL)
        q->__head = q->__tail;
}


void pop_q(queue * q)
{
    if(empty_q(q))
        return;

    if(q->__head == q->__tail)
    {
        __remove_node_q(q->__head);
        q->__head = NULL;
        q->__tail = NULL;

        return;
    }

    __node_q * cur = q->__tail;
    __node_q * del = q->__head;

    while(cur->__next != del)
        cur = cur->__next;

    __remove_node_q(del);

    cur->__next = NULL;
    q->__head = cur;
}


int empty_q(queue * q)
{
    return q->__head == NULL;
}


int count_q(queue * q)
{
    int count = 0;
    __node_q * cur = q->__tail;

    while(cur!=NULL)
    {
        count++;
        cur = cur->__next;
    }

    return count;
}


void clear_q(queue * q)
{
    if(q->__tail != NULL)
    {
        __node_q * cur = q->__tail, * cur2 = q->__tail->__next;
        while(cur2!=NULL)
        {
            __remove_node_q(cur);
            cur = cur2;
            cur2 = cur2->__next;
        }

        __remove_node_q(cur);
    }

    q->__head = NULL;
    q->__tail = NULL;
}


void print_d_q(queue * q)
{
    __node_q * cur = q->__tail;

    while(cur!=NULL)
    {
        printf("%d ", *(int *)cur->data);
        cur = cur->__next;
    }

    printf("\n");
}


int main()
{
    int a = 3, b = 4, c = 5, d = 6;
    int * pa = &a;
    int * pb = &b;
    int * pc = &c;
    int * pd = &d;

    queue * q = create_queue();
    push_q(q, (void*)pa);
    push_q(q, (void*)pb);
    push_q(q, (void*)pc);
    push_q(q, (void*)pd);
    pop_q(q);
    int front = *(int*)front_q(q);
    int back = *(int*)back_q(q);
    clear_q(q);
    print_d_q(q);
    printf("\n\n%d   %d", front, back);
}