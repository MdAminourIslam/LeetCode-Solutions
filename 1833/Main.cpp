#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int mx = *max_element(begin(costs), end(costs));

        vector<int> cnt(mx + 1, 0);
        for (int cost : costs) {
            cnt[cost] += 1;
        }

        int result = 0;

        for (int i = 1; i <= mx; i++) {
            int x = min(coins / i, cnt[i]);
            result += x;
            coins -= x * i;
        }
        return result;
    }
};