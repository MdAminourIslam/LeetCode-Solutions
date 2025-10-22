#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int n = nums.size();
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        long long best = 1;

        sort(nums.begin(), nums.end());

        for (int num : nums) {
            for (long long m : {num - k, num, num + k}) {
                long long low = m - k;
                long long high = m + k;

                auto l = lower_bound(nums.begin(), nums.end(), low);
                auto r = upper_bound(nums.begin(), nums.end(), high);
                
                long long cnt = r - l;
                long long same = freq[m];

                best = max(best, min(cnt, same + (long long)numOperations));
            }
        }
        return (int)best;
    }
};