#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long cnt = 0, ans = 0;
        for (int num : nums) {
            if (num == 0) {
                cnt++;
            } else {
                ans += cnt * (cnt + 1) / 2;
                cnt = 0;
            }
        }
        ans += cnt * (cnt + 1) / 2;
        return ans;
    }
};
