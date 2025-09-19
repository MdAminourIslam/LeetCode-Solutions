#include<stdio.h>

int longestSubarray(int* nums, int numsSize) {
    int mx = nums[0];
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] > mx) mx = nums[i];
    }

    int cnt = 0, ans = 1;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == mx) {
            cnt++;
            if (cnt > ans) ans = cnt;
        } else {
            cnt = 0;
        }
    }

    return ans;
}
