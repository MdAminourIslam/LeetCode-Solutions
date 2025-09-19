#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int left = 0;
        int curr_mask = 0;

        for (int right = 0; right < n; ++right) {
            while ((curr_mask & nums[right]) != 0) {
                curr_mask ^= nums[left];  
                ++left;
            }
            curr_mask |= nums[right];    
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};
