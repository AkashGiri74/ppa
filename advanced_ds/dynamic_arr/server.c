#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "dynamic_array.h"

array_t *create_array(s_size_t N) {
    array_t *p_arr = NULL;
    p_arr = (array_t *)xcalloc(1, sizeof(array_t));

    p_arr->N = N;
    p_arr->arr = (data_t *)xcalloc(N, sizeof(data_t));

    return p_arr;
}

void *xcalloc(size_t nr_elements, size_t size_per_element) {
    void *p = NULL;
    p = calloc(nr_elements, size_per_element);

    if (p == NULL) {
        fprintf(stderr, "fatal error: out of memory\n");
        exit(EXIT_FAILURE);
    }
    return p;
}

s_size_t size(array_t *p_arr) {
    return p_arr->N;
}

status_t set(array_t *p_arr, index_t index, data_t data) {
    if (index < 0 || index >= p_arr->N)
        return INDEX_OUT_OF_RANGE;

    p_arr->arr[index] = data;
    return SUCCESS;
}

void show(array_t *p_arr, const char *msg) {
    index_t index;

    if (msg != NULL)
        puts(msg);

    for (index = 0; index < p_arr->N; index++)
        printf("p_arr->arr[%lld]: %d\n", index, p_arr->arr[index]);
}
