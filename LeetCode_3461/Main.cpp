#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasSameDigits(string s) {
        while (s.size() > 2) {
            string cur = "";
            for (int i = 0; i + 1 < s.size(); i++) {
                int d = (s[i] - '0' + s[i + 1] - '0') % 10;
                cur.push_back(d + '0');
            }
            s = cur;
        }
        return s[0] == s[1];
    }
};