#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        string helper;
        for (char ch : s) {
            switch (ch) {
                case '(':
                    helper.push_back(')');
                    break;
                case '[':
                    helper.push_back(']');
                    break;
                case '{':
                    helper.push_back('}');
                    break;
                default:
                    if (helper.empty() || helper.back() != ch) return false;
                    helper.pop_back();
                    break;
            }
        }
        return helper.size() == 0;
    }
};