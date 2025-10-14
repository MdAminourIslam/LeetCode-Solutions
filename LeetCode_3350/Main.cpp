#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int answer = 1;
        int lastcnt = 0, cnt = 1;
        for (int i = 0; i + 1 < nums.size(); i++) {
            if (nums[i] < nums[i + 1]) {
                cnt += 1;
            } else {
                answer = max(answer, min(cnt, lastcnt));
                answer = max(answer, cnt / 2);
                lastcnt = cnt;
                cnt = 1;
            }
        }
        answer = max(answer, min(cnt, lastcnt));
        answer = max(answer, cnt / 2);
        return answer;
    }
};