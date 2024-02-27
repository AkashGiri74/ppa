#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dynamic_array.h"

int main() {
    s_size_t N = 10;
    array_t *pA = NULL;
    index_t index;
    status_t status;

    pA = create_array(N);

    for (index = 0; index < size(pA); index++) {
        status = set(pA, index, (index + 1) * 100);
        assert(status == SUCCESS);
    }
    show(pA, "after setting values");

    return 0;
}
