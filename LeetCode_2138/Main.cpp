#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> res;
        string cur;
        
        for (char ch : s) {
            cur.push_back(ch);

            if (cur.size() == k) {
                res.push_back(cur);
                cur.clear();
            }
        }

        while (!cur.empty() && cur.size() < k) {
            cur.push_back(fill);
        }

        if (cur.size() == k) {
            res.push_back(cur);
        }
        return res;
    }
};