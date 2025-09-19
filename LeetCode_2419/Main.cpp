#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int mx = *max_element(begin(nums), end(nums));
        int ans = 1, cnt = 0;

        for (int num : nums) {
            if (num == mx) {
                cnt += 1;
                ans = max(ans, cnt);
            } else {
                cnt = 0;
            }
        }
        return ans;
    }
};