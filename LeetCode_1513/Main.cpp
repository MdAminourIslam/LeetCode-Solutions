#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int mod = 1e9 + 7;
    int numSub(string s) {
        int cnt = 0;
        long long answer = 0;
        for (char ch : s) {
            if (ch == '1') {
                cnt += 1;
            } else {
                answer += 1LL * cnt * (cnt + 1) / 2;
                answer %= mod;
                cnt = 0;
            }
        }
        answer += cnt * (cnt + 1) / 2;
        answer %= mod;
        return (int)answer;
    }
};