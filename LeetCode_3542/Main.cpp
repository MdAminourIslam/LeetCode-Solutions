#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minOperations(vector<int>& nums) {
        vector<int> st;
        int ans = 0;

        for (int x : nums) {
            if (x == 0) {
                st.clear(); // reset
                continue;
            }

            while (!st.empty() && st.back() > x)
                st.pop_back();

            if (st.empty() || st.back() < x) {
                ans++;
                st.push_back(x);
            }
        }

        return ans;
    }
};
