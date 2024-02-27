
#ifndef _SSL_H
#define _SSL_H
#include<stddef.h>
struct node
{
    int data;
    struct node * next;
};


typedef int data_t  ;
typedef int status_t  ;
typedef int len_t;
typedef struct node node_t;
typedef node_t sll_t;

sll_t* create_list(void );
node_t* get_node(data_t new_data );
void * xmalloc(size_t size_in bytes);






#endif