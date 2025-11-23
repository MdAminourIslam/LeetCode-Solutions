#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int tot = 0;
        vector<int> b, c;
        for (int x : nums) {
            tot += x;
            if (x % 3 == 1) b.push_back(x);
            else if (x % 3 == 2) c.push_back(x);
        }
        
        sort(b.begin(), b.end());
        sort(c.begin(), c.end());
        
        if (tot % 3 == 0) return tot;
        
        int ans = 0;
        if (tot % 3 == 1) {
            int op1 = b.size() > 0 ? tot - b[0] : 0;
            int op2 = c.size() > 1 ? tot - c[0] - c[1] : 0;
            ans = max(op1, op2);
        } else {
            int op1 = b.size() > 1 ? tot - b[0] - b[1] : 0;
            int op2 = c.size() > 0 ? tot - c[0] : 0;
            ans = max(op1, op2);
        }
        
        return ans;
    }
};
