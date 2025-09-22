#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int n = nums.size();
        unordered_map<int, int> frequencyMap;
        for (int num : nums) {
            frequencyMap[num]++;
        }

        sort(nums.begin(), nums.end());

        int best = 0;
        for (int i = nums[0]; i <= nums.back(); i++) {
            best = max(best, helper(i, nums, frequencyMap, numOperations, k));
        }

        return best;
    }

private:
    int bisectLeft(const vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int ans = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                ans = mid;
                right = mid - 1;
            }
        }
        return ans;
    }

    int bisectRight(const vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int ans = nums.size();
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= target) {
                left = mid + 1;
            } else {
                ans = mid;
                right = mid - 1;
            }
        }
        return ans;
    }

    int helper(int x, const vector<int>& nums, unordered_map<int,int>& frequencyMap, int numOperations, int k) {
        int leftIndex = bisectLeft(nums, x - k);
        int rightIndex = bisectRight(nums, x + k);

        int same = frequencyMap.count(x) ? frequencyMap[x] : 0;
        int possibleChanges = min((rightIndex - leftIndex) - same, numOperations);
        return same + possibleChanges;
    }
};
