#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> cnt(26, 0);
        
        for (char ch : s) {
            cnt[ch - 'a']++;
        }
        for (char ch : t) {
            cnt[ch - 'a']--;
        }

        for (int x : cnt) {
            if (x) {
                return false;
            }
        }
        return true;
    }
};