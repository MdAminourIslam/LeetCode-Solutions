#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int helper(string &s, int x, int y) {
        int cnt_a = 0;
        int cnt_b = 0;
        int ab = 0;
        for (char ch : s) {
            if (ch == 'a') {
                cnt_a += 1;
            } else {
                if (cnt_a) {
                    ab += 1;
                    cnt_a -= 1;
                } else {
                    cnt_b += 1;
                }
            }
        }
        int ans1 = (ab * x) + min(cnt_a, cnt_b) * y;

        cnt_a = cnt_b = 0;
        int ba = 0;

        for (char ch : s) {
            if (ch == 'a') {
                if (cnt_b) {
                    ba += 1;
                    cnt_b -= 1;
                } else {
                    cnt_a += 1;
                }
            } else {
                cnt_b += 1;
            }
        }
        int ans2 = (ba * y) + min(cnt_a, cnt_b) * x;
        return max(ans1, ans2);
    }
    int maximumGain(string s, int x, int y) {
        string cur;
        vector<string> str;

        for (char ch : s) {
            if (ch == 'a' || ch == 'b') {
                cur.push_back(ch);
            } else {
                str.push_back(cur);
                cur.clear();
            }
        }

        if (!cur.empty()) {
            str.push_back(cur);
        }

        int ans = 0;
        for (string ss : str) {
            ans += helper(ss, x, y);
        }
        return ans;
    }
};