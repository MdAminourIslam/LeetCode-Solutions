#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> nums;
        for (auto& row : grid) {
            for (int element : row) {
                nums.push_back(element);
            }
        }

        for (int i = 1; i < nums.size(); i++) {
            if (abs(nums[i] - nums[0]) % x != 0) {
                return -1;
            }
        }

        sort(nums.begin(), nums.end());
        int median = nums[nums.size() / 2];

        int answer = 0;
        for (int val : nums) {
            answer += abs(val - median) / x;
        }

        return answer;
    }
};