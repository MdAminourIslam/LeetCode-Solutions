#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void isDecreasing(vector<int>& nums, vector<bool>& dec) {
        int n = nums.size();
        dec[n - 1] = true;
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] > nums[i + 1] && dec[i + 1]) {
                dec[i] = true;
            } else {
                dec[i] = false;
            }
        }
    }

    void suffixSumOfArray(vector<int>& nums, vector<long long>& suffix) {
        int n = nums.size();
        suffix[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + nums[i];
        }
    }

    long long splitArray(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dec(n, false);
        vector<long long> suffix(n, 0);

        isDecreasing(nums, dec);
        suffixSumOfArray(nums, suffix);

        long long minimum = 1e12;
        long long prefixSum = nums[0];
        bool inc = true;

        for (int i = 1; i < n; i++) {
            if (dec[i] && inc) {
                minimum = min(minimum, llabs(prefixSum - suffix[i]));
            }

            if (nums[i] <= nums[i - 1]) {
                inc = false;
            }

            prefixSum += nums[i];
        }

        return (minimum == (long long)1e12 ? -1 : minimum);
    }
};

