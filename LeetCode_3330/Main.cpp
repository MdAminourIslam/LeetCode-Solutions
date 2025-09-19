#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int possibleStringCount(string word) {
        int res = 1, cnt = 1;
        
        for (int i = 0; i + 1 < word.size(); i++) {
            if (word[i] == word[i + 1]) {
                cnt += 1;
            } else {
                res += cnt - 1;
                cnt = 1;
            }
        }
        res += cnt - 1;
        return res;
    }
};