#include <stdio.h>

int findTargetSumWays(int nums[], int n, int target) {
    if (n == 0) {
        // Base case: reached end of array, check if target is 0
        return (target == 0) ? 1 : 0;
    }
    
    // Calculate number of ways by considering adding and subtracting current element
    int add_ways = findTargetSumWays(nums + 1, n - 1, target - nums[0]);
    int subtract_ways = findTargetSumWays(nums + 1, n - 1, target + nums[0]);
    
    return add_ways + subtract_ways;
}

int main() {
    int nums[] = {1, 1, 1, 1, 1};
    int n = sizeof(nums) / sizeof(nums[0]);
    int target = 3;
    int ways = findTargetSumWays(nums, n, target);
    printf("Number of ways to reach the target sum: %d\n", ways);
    return 0;
}
