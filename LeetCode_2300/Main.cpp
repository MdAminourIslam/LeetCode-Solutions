#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int good(int spell, vector<int>& potions, long long success) {
        int ans = potions.size();
        int lo = 0, hi = potions.size() - 1;
    
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
    
            if (1LL * spell * potions[mid] >= success) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }

    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> answer;
        int n = potions.size();
        sort(potions.begin(), potions.end());

        for (int spell : spells) {
            answer.push_back(n - good(spell, potions, success));
        }

        return answer;
    }
};