#ifndef _SSL_H
#define _SSL_H
#define success 1
#define list_data_not_found 2
#include<stddef.h>
struct node
{
    int data;
    struct node *next;
};
typedef int data_t;
typedef int status_t;
typedef int len_t;
typedef struct node node_t;
typedef node_t sll_t;


sll_t* create_list(void);
node_t * get_node (data_t new_data);
void * xmalloc(size_t size_in_bytes);
void show_list(sll_t* p_list,const char * msg);
status_t insert_start(sll_t* p_list,data_t new_data);
status_t insert_end(sll_t* p_list,data_t new_data);
status_t insert_after(sll_t* p_list ,data_t e_data,data_t new_data);
status_t insert_before(sll_t* p_list ,data_t e_data,data_t new_data);
#endif