#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();

        vector<vector<int>> left(n, vector<int>(26, 0));
        vector<vector<int>> right(n, vector<int>(26, 0));

        for (int i = 0; i < n; i++) {
            left[i][s[i] - 'a'] = 1;
            right[i][s[i] - 'a'] = 1;
        }

        for (int i = 1; i < n; i++)
            for (int j = 0; j < 26; j++)
                left[i][j] += left[i - 1][j];

        for (int i = n - 2; i >= 0; i--)
            for (int j = 0; j < 26; j++)
                right[i][j] += right[i + 1][j];

        bool found[26][26] = {};  
        // found[mid][edge] = true if palindrome (edge, mid, edge) exists

        // For each possible middle
        for (int i = 1; i + 1 < n; i++) {
            int mid = s[i] - 'a';

            for (int ch = 0; ch < 26; ch++) {
                if (left[i - 1][ch] && right[i + 1][ch]) {
                    found[mid][ch] = true;
                }
            }
        }

        int ans = 0;
        for (int mid = 0; mid < 26; mid++)
            for (int ch = 0; ch < 26; ch++)
                ans += found[mid][ch];

        return ans;
    }
};
