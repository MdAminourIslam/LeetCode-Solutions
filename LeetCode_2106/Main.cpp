#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        const int mx = 2e5 + 2;
        vector<int> pre_sum(mx, 0);
        for (auto it : fruits) {
            pre_sum[it.front() + 1] = it.back();
        }
        
        for (int i = 1; i < mx; i++) {
            pre_sum[i] += pre_sum[i - 1];
        }

        int ans = 0;
        startPos += 1;

        for (int i = 0; i <= k; i++) {
            int left = max(startPos - i, 1);
            int right = min(left + k - i, 200000);
            ans = max(ans, pre_sum[right] - pre_sum[left - 1]);
        }

        for (int i = 0; i <= k; i++) {
            int right = min(startPos + i, 200001);
            int left = max(right + k - i, 1);
            ans = max(ans, pre_sum[right] - pre_sum[left - 1]);
        }

        return ans;
    }
};