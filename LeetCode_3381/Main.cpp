#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);

        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + nums[i];

        // store minimum prefix for each (i % k)
        vector<long long> minPrefix(k, LLONG_MAX);

        minPrefix[0] = 0;  // prefix[0] is 0

        long long ans = LLONG_MIN;

        for (int i = 1; i <= n; i++) {
            int rem = i % k;

            if (minPrefix[rem] != LLONG_MAX) {
                ans = max(ans, prefix[i] - minPrefix[rem]);
            }

            minPrefix[rem] = min(minPrefix[rem], prefix[i]);
        }

        return ans;
    }
};
