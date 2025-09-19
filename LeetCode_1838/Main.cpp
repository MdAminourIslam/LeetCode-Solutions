#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        vector<long long> prefix(n + 1, 0);

        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        int ans = 1;
        for (int i = 1; i < n; ++i) {
            int lo = 1, hi = i + 1;
            int best = 1;

            while (lo <= hi) {
                int mid = (lo + hi) / 2;

                long long total = prefix[i + 1] - prefix[i + 1 - mid];
                long long required = 1LL * nums[i] * mid;

                if (required - total <= k) {
                    best = mid;
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }

            ans = max(ans, best);
        }

        return ans;
    }
};
