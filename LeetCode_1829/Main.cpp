#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int mx = (1 << maximumBit) - 1;
        int n = nums.size();

        vector<int> ans(n), pre_xor(n);
        pre_xor[0] = nums[0];

        for (int i = 1; i < n; i++) {
            pre_xor[i] = pre_xor[i - 1] ^ nums[i];
        }
        for (int i = 0; i < n; i++) {
            ans[i] = pre_xor[n - i - 1] ^ mx;
        }
        return ans;
    }
};