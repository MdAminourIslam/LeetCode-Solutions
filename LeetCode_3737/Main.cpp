#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int answer = 0;

        for (int len = 1; len <= n; len++) {

            int cnt = 0;
            for (int i = 0; i < len; i++) {
                if (nums[i] == target) {
                    cnt += 1;
                }
            }

            if (cnt > len - cnt) {
                answer += 1;
            }

            for (int i = len; i < n; i++) {
                if (nums[i - len] == target) {
                    cnt -= 1;
                }

                if (nums[i] == target) {
                    cnt += 1;
                }

                if (cnt > len - cnt) {
                    answer += 1;
                }
            }

        }
        return answer;
    }
};