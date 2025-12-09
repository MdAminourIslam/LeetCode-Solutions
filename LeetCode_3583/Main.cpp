#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int mx = 1e5, mod = 1e9 + 7;
    int specialTriplets(vector<int>& nums) {
        vector<int> totalFreq(mx + 1, 0);
        vector<int> leftFreq(mx + 1, 0);

        for (int num : nums) {
            totalFreq[num] += 1;
        }

        int answer = 0;
        for (int num : nums) {
            if (1LL * num * 2 > 1LL * 100000) {
                leftFreq[num] += 1;
                continue;
            }
            
            int i = num * 2;
            int left = leftFreq[i];
            int right = totalFreq[i] - leftFreq[i];

            if (!num) right -= 1;
            
            leftFreq[num] += 1;
            answer += (int)((1LL * left * right) % mod);
            answer %= mod;
        }
        return answer;
    }
};