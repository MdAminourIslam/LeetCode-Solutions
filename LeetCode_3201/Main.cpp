#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int len = 0;
        int mod = 0;
        int odd = 0;
        for (int x : nums) {
            if (x % 2 != mod) {
                len += 1;
                mod = x & 1;
            }
            odd += (x & 1);
        }

        int mx = max({len, odd, (int)nums.size() - odd});
        len = 0, mod = 1;
        for (int x : nums) {
            if (x % 2 != mod) {
                len += 1;
                mod = x & 1;
            }
        }
        return max(mx, len);
    }
};