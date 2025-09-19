#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int ans = -1, premin = nums[0];
        for (int i = 1; i < n; ++i) {
            if (nums[i] > premin) {
                ans = (ans < nums[i] - premin ? nums[i] - premin : ans);
            } else {
                premin = nums[i];
            }
        }
        return ans;
    }
};