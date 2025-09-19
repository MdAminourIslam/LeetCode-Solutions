#include<stdio.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int maximumUniqueSubarray(int* nums, int numsSize) {
    int n = numsSize;
    int cnt[10001] = {0};
    
    int pre_sum[numsSize + 1];
    pre_sum[0] = 0;

    for (int i = 0; i < n; i++) {
        pre_sum[i + 1] = pre_sum[i] + nums[i];
    }
    int res = 0;
    for (int i = 1, j = 1; i <= n; i++) {
        while (cnt[nums[i - 1]]) {
            cnt[nums[j - 1]]--;
            j += 1;
        }
        cnt[nums[i - 1]]++;
        res = max(res, pre_sum[i] - pre_sum[j - 1]);
    }
    return res;
}