#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        vector<int> cnt(101, 0);
        for(int num : nums) {
            cnt[num]++;
        }

        int sum = 0;
        for(int i = 1; i <= 100; i++) {
            sum = cnt[i] == 1 ? sum + i : sum;
        }

        return sum;
    }
};
