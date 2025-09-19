#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        unordered_map<long long, long long> count;
        long long xorVal = 0, subArray = 0;
        count[0] = 1;

        for (long long num : nums) {
            xorVal ^= num;
            subArray += count[xorVal];
            count[xorVal]++;
        }
        return subArray;
    }
};
