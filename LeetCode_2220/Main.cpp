#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minBitFlips(int start, int goal) {
        int cnt = 0;
        for (int i = 0; i <= 30; i++) {
            if ((start & (1 << i)) != (goal & (1 << i))) {
                cnt += 1;
            }
        }
        return cnt;
    }
};