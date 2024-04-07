#include "sll.h"
#include <stdio.h>
#include <stdlib.h>

sll_t* create_list(void) {
    return get_node(0);
}

node_t* get_node(data_t new_data) {
    node_t* new_node = (node_t*)xmalloc(sizeof(node_t));
    new_node->data = new_data;
    new_node->next = NULL;
    return new_node;
}

void* xmalloc(size_t size_in_bytes) {
    void* ptr = malloc(size_in_bytes);
    if (ptr == NULL) {
        fprintf(stderr, "error in memory allocation ");
        exit(EXIT_FAILURE);
    }
    return ptr;
}

void show_list(sll_t* p_list, const char* msg) {
    node_t* run = p_list->next;
    if (msg != NULL)
        printf("%s\n", msg);
    printf("[start] -> ");
    while (run != NULL) {
        printf("[%d] -> ", run->data);
        run = run->next;
    }
    printf("[stop]\n");
}

status_t insert_start(sll_t* p_list, data_t new_data) {
    node_t* new_node = get_node(new_data);
    new_node->next = p_list->next;
    p_list->next = new_node;
    return success;
}

status_t insert_end(sll_t* p_list, data_t new_data) {
    node_t* run = p_list;
    while (run->next != NULL) {
        run = run->next;
    }
    run->next = get_node(new_data);
    return success;
}

status_t insert_after(sll_t* p_list, data_t e_data, data_t new_data) {
    node_t* run = p_list->next;
    while (run != NULL) {
        if (run->data == e_data) {
            node_t* new_node = get_node(new_data);
            new_node->next = run->next;
            run->next = new_node;
            return success;
        }
        run = run->next;
    }
    return list_data_not_found;
}

status_t insert_before(sll_t* p_list, data_t e_data, data_t new_data) {
    node_t* run = p_list->next;
    node_t* prev = p_list;
    while (run != NULL) {
        if (run->data == e_data) {
            node_t* new_node = get_node(new_data);
            new_node->next = run;
            prev->next = new_node;
            return success;
        }
        prev = run;
        run = run->next;
    }
    return list_data_not_found;
}

status_t get_start(sll_t* p_list, data_t* p_start_data) {
    if (p_list->next == NULL)
        return list_data_not_found;
    *p_start_data = p_list->next->data;
    return success;
}

status_t get_end(sll_t* p_list, data_t* p_end_data) {
    if (p_list->next == NULL)
        return list_data_not_found;
    node_t* temp = p_list;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    *p_end_data = temp->data;
    return success;
}

status_t remove_start(sll_t* p_list) {
    if (p_list->next == NULL)
        return list_data_not_found;
    node_t* temp = p_list->next;
    p_list->next = temp->next;
    free(temp);
    return success;
}

status_t remove_end(sll_t* p_list) {
    if (p_list->next == NULL)
        return list_data_not_found;
    node_t* temp = p_list;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return success;
}

status_t remove_data(sll_t* p_list, data_t r_data) {
    node_t* current = p_list;
    node_t* temp = NULL;
    while (current->next != NULL) {
        if (current->next->data == r_data) {
            temp = current->next;
            current->next = temp->next;
            free(temp);
            return success;
        }
        current = current->next;
    }
    return list_data_not_found;
}

status_t pop_start(sll_t* p_list, data_t* p_start_data) {
    if (p_list->next == NULL)
        return list_data_not_found;
    *p_start_data = p_list->next->data;
    return remove_start(p_list);
}

status_t pop_end(sll_t* p_list, data_t* p_end_data) {
    if (p_list->next == NULL)
        return list_data_not_found;
    node_t* temp = p_list;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    *p_end_data = temp->next->data;
    free(temp->next);
    temp->next = NULL;
    return success;
}

status_t clear_list(sll_t* p_list) {
    node_t* current = p_list->next;
    node_t* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    p_list->next = NULL; // Set the head to NULL
    return success;
}

status_t is_list_empty(sll_t* p_list) {
    return p_list->next == NULL ? success : list_data_not_found;
}

status_t find(sll_t* p_list, data_t f_data) {
    node_t* current = p_list->next;
    while (current != NULL) {
        if (current->data == f_data)
            return success;
        current = current->next;
    }
    return list_data_not_found;
}

len_t get_list_length(sll_t* p_list) {
    len_t length = 0;
    node_t* current = p_list->next;
    while (current != NULL) {
        length++;
        current = current->next;
    }
    return length;
}

status_t destroy_list(sll_t** pp_list) {
    clear_list(*pp_list); // Clear the list
    free(*pp_list); // Free the list structure itself
    *pp_list = NULL; // Set the pointer to NULL
    return success;
}
