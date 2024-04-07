#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "sll.h"

void main() {
    status_t status;
    data_t start_data, end_data;
    sll_t* p_list = NULL;

    p_list = create_list();
    assert(p_list != NULL);
    show_list(p_list, "After creating list");

    status = insert_start(p_list, 10);
    assert(status == success);
    show_list(p_list, "After inserting at start: 10");

    status = insert_start(p_list, 20);
    assert(status == success);
    show_list(p_list, "After inserting at start: 20");

    status = insert_end(p_list, 30);
    assert(status == success);
    show_list(p_list, "After inserting at end: 30");

    status = insert_after(p_list, 10, 15);
    assert(status == success);
    show_list(p_list, "After inserting after 10: 15");

    status = insert_before(p_list, 20, 25);
    assert(status == success);
    show_list(p_list, "After inserting before 20: 25");

    status = get_start(p_list, &start_data);
    assert(status == success);
    status = get_end(p_list, &end_data);
    assert(status == success);
    printf("Start data: %d, End data: %d\n", start_data, end_data);

    status = remove_start(p_list);
    assert(status == success);
    show_list(p_list, "After removing start");

    status = remove_end(p_list);
    assert(status == success);
    show_list(p_list, "After removing end");

    status = remove_data(p_list, 15); // Remove node with data 15
    assert(status == success);
    show_list(p_list, "After removing data 15");

    status = pop_start(p_list, &start_data);
    assert(status == success);
    printf("Popped start data: %d\n", start_data);
    show_list(p_list, "After popping start");

    status = pop_end(p_list, &end_data);
    assert(status == success);
    printf("Popped end data: %d\n", end_data);
    show_list(p_list, "After popping end");

    status = clear_list(p_list);
    assert(status == success);
    show_list(p_list, "After clearing list");

    status = is_list_empty(p_list);
    assert(status == success);
    printf("Is list empty? %s\n", status == success ? "Yes" : "No");

    status = find(p_list, 20); // Data 20 should not be found in the empty list
    assert(status == list_data_not_found);

    status = destroy_list(&p_list);
    assert(status == success);
}
