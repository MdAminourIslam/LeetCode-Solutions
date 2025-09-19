#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sum = nums.back(), mx = nums.back();

        reverse(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
                sum += nums[i];
                mx = max(mx, sum);
            }
        }
        return mx;
    }
};