#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int findLucky(vector<int>& arr) {
        vector<int> cnt(501);
        
        for (int x : arr) {
            cnt[x]++;
        }

        for (int i = 500; i >= 1; i--) {
            if (cnt[i] == i) {
                return i;
            }
        }
        return -1;
    }
};