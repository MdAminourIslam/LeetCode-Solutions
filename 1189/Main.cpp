#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        map<char, int> cnt;
        for (char ch : text) {
            cnt[ch] += 1;
        }

        int mn = 100001;

        for (char ch : {'b', 'a', 'l', 'o', 'n'}) {
            if (ch == 'l' or ch == 'o') {
                mn = min(mn, cnt[ch] / 2);
            } else {
                mn = min(mn, cnt[ch]);
            }
        }
        return mn;
    }
};