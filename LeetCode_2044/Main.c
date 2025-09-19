#include<stdio.h>

int countMaxOrSubsets(int* nums, int n) {
    int maxOr = 0, cnt = 0;
    int sz = 1 << n;
    
    for (int mask = 0; mask < sz; ++mask) {
        int cur = 0;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                cur |= nums[i];
            }
        }
        if (cur > maxOr) {
            maxOr = cur;
            cnt = 1;
        } else if (cur == maxOr) {
            cnt++;
        }
    }
    return cnt;
}
