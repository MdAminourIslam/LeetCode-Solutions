#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int helper2(string s) {
        return stoi(s);
    }

    vector<int> helper1(string s) {
        string cur = "";
        vector<int> version;
        for (char ch : s) {
            if (ch == '.') {
                version.push_back(helper2(cur));
                cur = "";
            } else {
                cur += ch;
            }
        }
        version.push_back(helper2(cur));
        return version;
    }
    int compareVersion(string version1, string version2) {
        vector<int> v1 = helper1(version1);
        vector<int> v2 = helper1(version2);

        int n = max(v1.size(), v2.size());

        for (int i = 0; i < n; i++) {
            int num1 = (i < v1.size() ? v1[i] : 0);
            int num2 = (i < v2.size() ? v2[i] : 0);
            
            if (num1 < num2) {
                return -1;
            }
            if (num1 > num2) {
                return 1;
            }
        }
        return 0;
    }
};