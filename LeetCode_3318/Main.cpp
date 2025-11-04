#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> ans;
        
        for (int i = 0; i <= nums.size() - k; i++) {
            vector<int> cnt(51, 0);
            int sum = 0;
            
            for (int j = i; j < i + k; j++) {
                cnt[nums[j]]++;
            }
            
            vector<pair<int, int>> a;
            for (int j = 1; j <= 50; j++) {
                if (cnt[j] > 0) {
                    a.push_back({-cnt[j], -j});
                }
            }
            
            sort(a.begin(), a.end());
            
            for (int j = 0; j < min(x, (int)a.size()); j++) {
                sum += a[j].first * a[j].second;
            }
            
            ans.push_back(sum);
        }
        
        return ans;
    }
};