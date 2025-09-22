#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> cnt(101, 0);
        for (int num : nums) {
            cnt[num] += 1;
        }
        int mx = *max_element(begin(cnt), end(cnt));
        int sum = 0;
        for (int c : cnt) {
            sum = (c == mx ? sum + c : sum);
        }
        return sum;
    }
};