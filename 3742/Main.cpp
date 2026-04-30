#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n, m;
    vector<vector<vector<int>>> dp;

    int dfs(int i, int j, vector<vector<int>>& grid, int k, int cost) {

        if (i >= n || j >= m) return -1e9;

        cost += (grid[i][j] > 0);
        if (cost > k) return -1e9;

        if (i == n-1 && j == m-1)
            return grid[i][j];

        int &res = dp[i][j][cost];
        if (res != -1) return res;

        int right = dfs(i, j+1, grid, k, cost);
        int down  = dfs(i+1, j, grid, k, cost);

        int best = max(right, down);

        if (best < 0) return res = -1e9;

        return res = grid[i][j] + best;
    }

    int maxPathScore(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();

        dp.assign(n, vector<vector<int>>(m, vector<int>(k+1, -1)));

        int ans = dfs(0, 0, grid, k, 0);

        return (ans < 0 ? -1 : ans);
    }
};