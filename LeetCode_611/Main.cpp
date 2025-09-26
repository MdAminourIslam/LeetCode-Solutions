#include<bits/stdc++.h>
using namespace std;

int lowerBound(vector<int>& nums, int target) {
    int lo = 0, hi = nums.size(); 
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;

        if (nums[mid] < target) {
            lo = mid + 1; 
        } else {
            hi = mid;    
        }
    }
    return lo; // nums[index] >= target
}

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int n = nums.size();
        int result = 0;

        for (int i = 0; i + 1 < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (!nums[i] or !nums[j]) continue;

                int sum = nums[i] + nums[j];
                int lo = lowerBound(nums, sum);
                result += lo - j - 1;
            }
        }
        return result;
    }
};
