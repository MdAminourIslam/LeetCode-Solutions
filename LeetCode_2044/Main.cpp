#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr = 0, count = 0;
        int n = nums.size();
        int total = 1 << n;
        
        for (int mask = 0; mask < total; ++mask) {
            int cur = 0;
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    cur |= nums[i];
                }
            }
            if (cur > maxOr) {
                maxOr = cur;
                count = 1;
            } else if (cur == maxOr) {
                count++;
            }
        }
        return count;
    }
};
