#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        vector<int> cnt(1001, 0);
        for (int x : nums) {
            cnt[x] += 1;
        }

        while (original < 1001 and cnt[original]) {
            original *= 2;
        }
        return original;
    }
};