#ifndef _SLL_H
#define _SLL_H

#include <stddef.h>

#define success 1
#define list_data_not_found 2

typedef int data_t;
typedef int status_t;
typedef int len_t;

struct node {
    int data;
    struct node* next;
};

typedef struct node node_t;
typedef node_t sll_t;

sll_t* create_list(void);
node_t* get_node(data_t new_data);
void* xmalloc(size_t size_in_bytes);
void show_list(sll_t* p_list, const char* msg);
status_t insert_start(sll_t* p_list, data_t new_data);
status_t insert_end(sll_t* p_list, data_t new_data);
status_t insert_after(sll_t* p_list, data_t e_data, data_t new_data);
status_t insert_before(sll_t* p_list, data_t e_data, data_t new_data);
status_t get_start(sll_t* p_list, data_t* p_start_data);
status_t get_end(sll_t* p_list, data_t* p_end_data);
status_t remove_start(sll_t* p_list);
status_t remove_end(sll_t* p_list);
status_t remove_data(sll_t* p_list, data_t r_data);
status_t pop_start(sll_t* p_list, data_t* p_start_data);
status_t pop_end(sll_t* p_list, data_t* p_end_data);
status_t clear_list(sll_t* p_list);
status_t is_list_empty(sll_t* p_list);
status_t find(sll_t* p_list, data_t f_data);
len_t get_list_length(sll_t* p_list);
status_t destroy_list(sll_t** pp_list);


#endif  // _SLL_H
