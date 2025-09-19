#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n, 1), right(n, 1);

        int cur = 0;
        for (int i = 0; i < n; i++) {
            while (cur < n && heights[i] <= heights[cur]) {
                cur += 1;
            }
            right[i] = cur - i;
        }

        cur = n - 1;
        for (int i = n - 1; i >= 0; i--) {
             while (cur >= 0 && heights[i] <= heights[cur]) {
                cur -= 1;
            }
            right[i] = i - cur;
        }
        int ans = 1;
        for (int i = 0; i < n; i++) {
            ans = max(ans, (left[i] + right[i] - 1) * heights[i]);
        }
        return ans;
    }
};