#include <stdio.h>

int maximumDifference(int* nums, int numsSize) {
    int ans = -1, premin = nums[0];
    for (int i = 1; i < numsSize; ++i) {
        if (nums[i] > premin) {
            ans = (ans < nums[i] - premin ? nums[i] - premin : ans);
        } else {
            premin = nums[i];
        }
    }
    return ans;
}

int main() {
    int n = 4;
    int nums[] = {7, 1, 5, 4};
    printf("%d", maximumDifference(nums, n));
}
