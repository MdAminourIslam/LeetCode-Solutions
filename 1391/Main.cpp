#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n, m;
    vector<vector<int>> vis;

    void dfs(int i, int j, vector<vector<int>>& grid) {
        if (i < 0 || i >= n || j < 0 || j >= m || vis[i][j]) {
            return;
        }

        vis[i][j] = 1;
        int current = grid[i][j];

        if (current == 1) {
            if (j + 1 < m && (grid[i][j+1] == 1 || grid[i][j+1] == 3 || grid[i][j+1] == 5)) dfs(i, j + 1, grid);
            if (j - 1 >= 0 && (grid[i][j-1] == 1 || grid[i][j-1] == 4 || grid[i][j-1] == 6)) dfs(i, j - 1, grid);
        }
        else if (current == 2) {
            if (i + 1 < n && (grid[i+1][j] == 2 || grid[i+1][j] == 5 || grid[i+1][j] == 6)) dfs(i + 1, j, grid);
            if (i - 1 >= 0 && (grid[i-1][j] == 2 || grid[i-1][j] == 3 || grid[i-1][j] == 4)) dfs(i - 1, j, grid);
        }
        else if (current == 3) {
            if (i + 1 < n && (grid[i+1][j] == 2 || grid[i+1][j] == 5 || grid[i+1][j] == 6)) dfs(i + 1, j, grid);
            if (j - 1 >= 0 && (grid[i][j-1] == 1 || grid[i][j-1] == 4 || grid[i][j-1] == 6)) dfs(i, j - 1, grid);
        }
        else if (current == 4) {
            if (i + 1 < n && (grid[i+1][j] == 2 || grid[i+1][j] == 5 || grid[i+1][j] == 6)) dfs(i + 1, j, grid);
            if (j + 1 < m && (grid[i][j+1] == 1 || grid[i][j+1] == 3 || grid[i][j+1] == 5)) dfs(i, j + 1, grid);
        }
        else if (current == 5) {
            if (i - 1 >= 0 && (grid[i-1][j] == 2 || grid[i-1][j] == 3 || grid[i-1][j] == 4)) dfs(i - 1, j, grid);
            if (j - 1 >= 0 && (grid[i][j-1] == 1 || grid[i][j-1] == 4 || grid[i][j-1] == 6)) dfs(i, j - 1, grid);
        }
        else if (current == 6) {
            if (i - 1 >= 0 && (grid[i-1][j] == 2 || grid[i-1][j] == 3 || grid[i-1][j] == 4)) dfs(i - 1, j, grid);
            if (j + 1 < m && (grid[i][j+1] == 1 || grid[i][j+1] == 3 || grid[i][j+1] == 5)) dfs(i, j + 1, grid);
        }
    }

    bool hasValidPath(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vis.assign(n, vector<int>(m, 0));
        dfs(0, 0, grid);
        return vis[n - 1][m - 1] == 1;
    }
};
