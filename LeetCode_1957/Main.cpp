#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string makeFancyString(string s) {
        string res;
        for (int i = 0; i < s.size(); i++) {
            if (res.size() < 2) {
                res.push_back(s[i]);
            } else {
                int sz = res.size();
                if (res[sz - 1] == res[sz - 2] && res[sz - 1] == s[i]) {
                    continue;
                } else {
                    res.push_back(s[i]);
                }
            }
        }
        return res;
    }
};