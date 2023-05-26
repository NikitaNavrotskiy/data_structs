#include <stdio.h>
#include <stdlib.h>


typedef struct __node_s
{
    void * data;
    struct __node_s * __next;
}__node_s;


typedef struct stack
{
    __node_s * __head;
}stack;


__node_s * __create_node_s(void * data, __node_s * __next);

void __remove_node_s(__node_s * nd);

stack * create_stack();

void * top_s(stack * s);

void push_s(stack * s, void * data);

void pop_s(stack * s);

int empty_s(stack * s);

int size_s(stack * s);

void clear_stack(stack * s);

void remove_stack(stack * s);