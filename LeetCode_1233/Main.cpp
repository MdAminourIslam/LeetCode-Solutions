#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        set<string> res;
        sort(folder.begin(), folder.end());

        for (string s : folder) {
            bool subFolder = false;
            for (int i = 1; i < s.size(); i++) {
                if (s[i] == '/' and res.find(s.substr(0, i)) != res.end()) {
                    subFolder = true;
                    break;
                }
            }
            if (!subFolder) {
                res.insert(s);
            }
        }
        return {res.begin(), res.end()};
    }
};