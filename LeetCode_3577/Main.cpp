#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPermutations(vector<int>& c) {
        const int MOD = 1e9+7;
        int n = c.size();
        
        // If any complexity[i] <= complexity[0], impossible to unlock
        for (int i = 1; i < n; i++) {
            if (c[i] <= c[0]) return 0;
        }

        // Compute (n-1)!
        long long res = 1;
        for (int i = 1; i < n; i++) {
            res = (res * i) % MOD;
        }
        return res;
    }
};
