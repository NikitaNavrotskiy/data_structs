
typedef struct node{
    void * data;
    struct node * next;
    struct node * prev;
}node;

typedef struct list{
    node * head;
}list;




node * create_node(void * data, node * next, node * prev);

void remove_node(node * nd);





list * create_list();

void add_end(list * lst, void * data);

void add_start(list * lst, void * data);

void add_after(list * lst, node * nd, void * data);

void print(list * lst);

void pop(list * lst, node * nd);

long count(list * lst);

void remove_list(list * lst);