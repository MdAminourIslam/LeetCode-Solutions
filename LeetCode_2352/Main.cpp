#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>, int> cnt1, cnt2;

        int n = grid.size();
        vector<int> temp(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                temp[j] = grid[i][j];
            }
            cnt1[temp]++;
            for (int j = 0; j < n; j++) {
                temp[j] = grid[j][i];
            }
            cnt2[temp]++;
        }
        int ans = 0;
        for (auto u : cnt1) {
            ans += u.second * cnt2[u.first];
        }
        return ans;
    }
};