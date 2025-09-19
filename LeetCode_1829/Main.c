#include<stdio.h>
#include<math.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getMaximumXor(int* nums, int numsSize, int maximumBit, int* returnSize) {
    int mx = (1 << maximumBit) - 1;
    int* ans = (int*)malloc(numsSize * sizeof(int));
    int* pre_xor = (int*)malloc(numsSize * sizeof(int));
    
    pre_xor[0] = nums[0];
    for (int i = 1; i < numsSize; i++) {
        pre_xor[i] = pre_xor[i - 1] ^ nums[i];
    }

    for (int i = 0; i < numsSize; i++) {
        ans[i] = pre_xor[numsSize - i - 1] ^ mx;
    }

    *returnSize = numsSize;
    return ans;
}
