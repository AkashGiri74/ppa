#include <stdio.h>

int minStepsToTop(int n) {
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;
    
    int prev = 1;
    int curr = 2;
    int next;

    for (int i = 3; i <= n; i++) {
        next = prev + curr;
        prev = curr;
        curr = next;
    }

    return curr;
}

int main() {
    int n = 5;
    printf("Minimum number of steps required to reach the top: %d\n", minStepsToTop(n));
}
 