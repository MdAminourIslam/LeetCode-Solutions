#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n);
        prefix[0] = nums[0];

        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }

        vector<int> answer(n);
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                answer[i] = prefix[n - 1] - prefix[i] - nums[i] * (n - 1);
            } else if (i + 1 == n) {
                answer[i] = nums[i] * (n - 1) - prefix[i - 1];
            } else {
                answer[i] = nums[i] * i - prefix[i - 1] + prefix[n - 1] - prefix[i] - nums[i] * (n - i - 1);
            }
        }
        return answer;
    }
};