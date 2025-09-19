#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(string s) {
        vector<int> cnt(26);
        for (char ch : s) {
            if (ch != 'a') {
                cnt[ch - 'a']++;
            }
        }

        int op = 0;
        for (int i = 1; i < 25; i++) {
            if (cnt[i]) {
                op += 1;
                cnt[i + 1] += cnt[i];
            }
        }
        if (cnt[25]) {
            op += 1;
        }
        return op;
    }
};