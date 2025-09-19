#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre_sum(n + 1);

        for (int i = 0; i < n; i++) {
            pre_sum[i + 1] = pre_sum[i] + nums[i];
        }

        int cnt[10001] = {0};
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
};


