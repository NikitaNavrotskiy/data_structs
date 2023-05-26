
typedef struct __node{
    void * data;
    struct __node * __next;
    struct __node * __prev;
}__node;


typedef struct list{
    __node * __head;
    __node * __tail;
}list;



// private

__node * __create_node_l(void * data, __node * next, __node * prev);

void __remove_node_l(__node * nd);



// public


list * create_list();

void push_back_l(list * lst, void * data);

void push_front_l(list * lst, void * data);

void pop_front_l(list * lst);

void pop_back_l(list * lst);

void * front_l(list * lst);

void * back_l(list * lst);

int count_list(list * lst);

void print_d_l(list * lst);

void printr_d_l(list * lst);

void remove_list(list * lst);

void clear_list(list * lst);

