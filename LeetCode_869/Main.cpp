#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string target = sortedString(n);
        for (int i = 0; i < 31; i++) {
            if (target == sortedString(1 << i)) return true;
        }
        return false;
    }
    
    string sortedString(int x) {
        string s = to_string(x);
        sort(s.begin(), s.end());
        return s;
    }
};
