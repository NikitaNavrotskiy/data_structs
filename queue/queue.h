#include <stdio.h>
#include <stdlib.h>



typedef struct __node_q
{
    void * data;
    struct __node_q * __next;
}__node_q;


typedef struct queue
{
    __node_q * __head;
    __node_q * __tail;
}queue;



__node_q * __create_node_q(void * data, __node_q * __next);


queue * create_queue();

void * front_q(queue * q);

void * back_q(queue * q);

void push_q(queue * q, void * data);

void pop_q(queue * q);

int empty_q(queue * q);

int count_q(queue * q);

void clear_q(queue * q);

void print_d_q(queue * q);