#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        map<int, int> cnt;
        int ans = 2;

        for (int i = 0, j = 0; i < fruits.size(); i++) {
            cnt[fruits[j]]++;
            while (cnt.size() > 2) {
                cnt[fruits[j]]--;
                if (cnt[fruits[j]] == 0) {
                    cnt.erase(fruits[j]);
                }
            }
            ans = max(ans, (int)cnt.size());
        }
        return ans;
    }
};