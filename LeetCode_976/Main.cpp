#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        sort(begin(nums), end(nums));
        int mx = 0;
        for (int i = 0; i + 2 < n; i++) {
            if (nums[i] + nums[i + 1] > nums[i + 2]) {
                mx = nums[i] + nums[i + 1] + nums[i + 2];
            }
        }
        return mx;
    }
};