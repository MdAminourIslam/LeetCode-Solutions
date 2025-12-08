#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        vector<vector<int>> cnt(11, vector<int> (11, 0));

        long long answer = 0;
        for (int i = 0; i < nums.size(); i++) {
            string s = to_string(nums[i]);
            for (int j = 0; j < s.size(); j++) {
                int c = 0;
                for (int k = 0; k < 10; k++) {
                    c += cnt[j][k];
                }
                c -= cnt[j][s[j] - '0'];
                cnt[j][s[j] - '0'] += 1;
                answer += c;
            }
        }
        return answer;
    }
};