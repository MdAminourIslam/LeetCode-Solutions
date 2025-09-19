#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    char repeatedCharacter(string s) {
        int cnt[26] = {0};
        for (int i = 0; i < s.size(); i++) {
            if (cnt[s[i] - 'a']) {
                return s[i];
            }
            cnt[s[i] - 'a']++;
        }
        return ' ';
    }
};