#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    void generatePascal(int i, vector<vector<int>> &dp) {
        if (i == 0) {
            dp[0] = {1};
            return;
        }
        if (dp[i - 1].empty()) { 
            generatePascal(i - 1, dp); // Ensure the previous row is computed
        }
        dp[i].resize(i + 1);
        dp[i][0] = dp[i][i] = 1;
        for (int j = 1; j < i; j++) {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> dp(numRows);
        generatePascal(numRows - 1, dp);
        return dp;
    }
};




