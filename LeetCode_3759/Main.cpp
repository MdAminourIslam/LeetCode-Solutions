#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        if (k == 0) return n;
        int cnt = 0;
        for (int num : nums) {
            if (num < nums[n - k]) {
                cnt += 1;
            }
        }
        return cnt;
    }
};