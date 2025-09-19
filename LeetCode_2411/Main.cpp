#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        vector<int> indx[33];
        int mx_or = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            mx_or |= nums[i];
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 31; j++) {
                if (nums[i] & (1 << j)) {
                    indx[j].push_back(i);
                }
            }
        }

        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            int mx_j = i;
            for (int j = 0; j < 31; j++) {
                if (mx_or & (1 << j)) {
                    auto it = lower_bound(indx[j].begin(), indx[j].end(), i);
                    if (it != indx[j].end()) {
                        mx_j = max(mx_j, *it);
                    }
                }
            }
            ans[i] = mx_j - i + 1;
        }
        return ans;
    }
};
