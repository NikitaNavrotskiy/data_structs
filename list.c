#include "list.h"
#include <stdio.h>
#include <stdlib.h>


node * create_node(void * data, node * next, node * prev){
    node * tmp = (node *)malloc(sizeof(node));

    if(tmp == NULL)
        return NULL;

    tmp->data = data;
    tmp->next = next;
    tmp->prev = prev;

    return tmp;
}

void remove_node(node * nd){
    free(nd);
}


list * create_list(){
    list * tmp = (list *)malloc(sizeof(list));

    if(tmp == NULL){
        return NULL;
    }

    return tmp;
}


void remove_list(list * lst){
    node * cur = lst->head;
    switch (count(lst))
    {
    case 2:
        remove_node(cur->next);
        remove_node(cur);
        free(lst);
        return;
    case 1:
        remove_node(cur);
        free(lst);
        return;
    case 0:
        free(lst);
        return;
    default:
        break;
    }

    while(cur->next->next != NULL)
        cur = cur->next;
    
    do{
        remove_node(cur->next);
        cur = cur->prev;
    }while(cur!=lst->head);

    remove_node(cur);
    free(lst);
}


void add_end(list * lst, void * data){
    node * tmp = create_node(data, NULL, NULL);
    if(lst->head == NULL){
        lst->head = tmp;
        return;
    }

    node * cur = lst->head;
    while(cur->next!=NULL)
        cur = cur->next;

    cur->next = tmp;
    tmp->prev = cur;
    return;
}


void add_start(list * lst, void * data){
    node * tmp = create_node(data, NULL, NULL);
    tmp->next = lst->head;
    lst->head->prev = tmp;
    lst->head = tmp;
}


void print(list * lst){
    if(lst->head == NULL)
        return;
    node * cur = lst->head;
    for(; cur!=NULL; cur = cur->next)
        printf("%d ", *(int*)cur->data);
    
    printf("\n");
}  


void pop(list * lst, node * nd){
    node * del = NULL, *cur = NULL;
    if(lst->head->next == NULL){
        del = lst->head;
        lst->head = NULL;
        remove_node(del);
        return;
    }
    if(lst->head == nd){
        lst->head = lst->head->next;
        if(lst->head->next != NULL)
            lst->head->next->prev = NULL;
        remove_node(del);
        return;
    }

    cur = lst->head;
    while(cur->next!=NULL){
        if(cur->next == nd)
            break;
        cur = cur->next;
    }
    
    if(cur->next == NULL)
        return;

    if(cur->next->next!=NULL){
        del = cur->next;
        cur->next = del->next;
        del->next->prev = cur;
        remove_node(del);
    }
    else{
        del = cur->next;
        cur->next = NULL;
        remove_node(del);
    }
}


long count(list * lst){
    if(lst->head == NULL)
        return 0;

    long res = 1;
    node * cur = lst->head;
    while(cur->next!=NULL){
        res++;
        cur = cur->next;
    }
    return res;
}


void add_after(list * lst, node * nd, void * data){
    if(lst->head == NULL)
        return;
    node * tmp = create_node(data, NULL, NULL);
    node * cur = lst->head;
    if(lst->head == nd){
        if(cur->next == NULL){
            cur->next = tmp;
            tmp->prev = NULL;
        }
        else{
            tmp->prev = cur;
            tmp->next = lst->head->next;
            lst->head->next->prev = tmp;
            cur->next = tmp;
        }
    } 
        
    while(cur->next != NULL){
        if(cur->next == nd)
            break;
        cur = cur->next;
    }
    if(cur->next == NULL)
        return;

    if(cur->next->next!=NULL){
        tmp->next = cur->next->next;
        tmp->prev = cur->next;
        cur->next->next = tmp;
        cur->next->next->prev = tmp;
    }
    else{
        cur->next->next = tmp;
        tmp->prev = cur->next->next;
    }
}




