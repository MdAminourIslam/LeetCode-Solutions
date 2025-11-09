#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();

        int answer = 0;
        int cnt = 1;
        for (int i = 0; i + 1 < n; i++) {
            if (nums[i] <= nums[i + 1]) {
                cnt += 1;
            } else {
                
                int j = i + 1;
                int c = 1;
                while (j + 1 < n) {
                    if (nums[j] <= nums[j + 1]) {
                        c += 1;
                    } else {
                        break;
                    }
                    j += 1;
                }
                if (i + 2 < n && nums[i + 2] >= nums[i]) {
                    answer = max(answer, cnt + c);
                } else if (i - 1 >= 0 && nums[i + 1] >= nums[i - 1]) {
                    answer = max(answer, cnt + c);
                } else {
                    answer = max(answer, cnt + 1);
                }

                if (answer == n) {
                    return answer;
                }

                cnt = 1;
            }
        }
        
        if (cnt < n) {
            answer = max(answer, cnt + 1);
        }
        answer = max(answer, cnt);
        return answer;
    }
};