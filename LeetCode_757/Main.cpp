#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
             [](auto &a, auto &b) {
                 if (a[1] == b[1]) return a[0] > b[0];
                 return a[1] < b[1];
             });

        int a = -1, b = -1; 
        int ans = 0;

        for (auto &in : intervals) {
            int L = in[0], R = in[1];

            bool hasA = (a >= L);
            bool hasB = (b >= L);

            if (hasA && hasB) {
                continue;
            } else if (hasB) {
                a = b;
                b = R;
                ans++;
            } else {
                a = R - 1;
                b = R;
                ans += 2;
            }
        }
        return ans;
    }
};