#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int mod = 1e9 + 7;
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k, 0)));

        dp[0][0][grid[0][0] % k] = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i > 0) {
                    for (int kk = 0; kk < k; kk++) {
                        if (dp[i - 1][j][kk]) {
                            int newRem = (kk + grid[i][j]) % k;
                            dp[i][j][newRem] += dp[i - 1][j][kk];
                            dp[i][j][newRem] %= mod;
                        }
                    }
                }

                if (j > 0) {
                    for (int kk = 0; kk < k; kk++) {
                        if (dp[i][j - 1][kk]) {
                            int newRem = (kk + grid[i][j]) % k;
                            dp[i][j][newRem] += dp[i][j - 1][kk];
                            dp[i][j][newRem] %= mod;
                        }
                    }
                }
            }
        }
        return dp[n - 1][m - 1][0];
    }
};