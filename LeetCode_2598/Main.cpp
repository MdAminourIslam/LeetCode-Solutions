#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        map<int, int> cnt;

        for (int num : nums) {
            cnt[((num % value) + value) % value]++;
        }

        int mex = 0;

        while (cnt[mex % value]) {
            cnt[mex % value]--;
            mex += 1;
        }

        return mex;
    }
};