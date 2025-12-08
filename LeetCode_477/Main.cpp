#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        vector<int> cnt(32);

        int sumOfHD = 0; // Sum of Hamming distances

        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < 32; j++) {
                if (nums[i] & (1 << j)) {
                    sumOfHD += i - cnt[j];
                    cnt[j] += 1;
                } else {
                    sumOfHD += cnt[j];
                }
            }
        }
        return sumOfHD;
    }
};