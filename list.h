
typedef struct node{
    void * data;
    struct node * __next;
    struct node * __prev;
}node;

typedef struct list{
    node * __head;
    node * __tail;
}list;



// private

node * __create_node(void * data, node * next, node * prev);

void __remove_node(node * nd);



// public


list * create_list();

void push_back(list * lst, void * data);

void push_front(list * lst, void * data);

void pop_front(list * lst);

void pop_back(list * lst);

node * front(list * lst);

node * back(list * lst);

int count_list(list * lst);

void print_d(list * lst);

void printr_d(list * lst);

void remove_list(list * lst);

void clear_list(list * lst);

