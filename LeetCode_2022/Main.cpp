#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int len = original.size();
        if (len != n * m) {
            return {};
        }

        vector<vector<int>> grid(m, vector<int> (n, 0));
        for (int row = 0, i = 0; i < len; i++) {
            if (i and i % n == 0) {
                row += 1;
            }
            int col = i % n;
            grid[row][col] = original[i];
        }
        return grid;
    }
};

