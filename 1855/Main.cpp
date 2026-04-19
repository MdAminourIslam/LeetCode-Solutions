#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0, ans = 0;

        while (i < nums1.size()) {
            while (j < nums2.size() && nums2[j] >= nums1[i]) {
                j++;
            }

            if (j >= i + 1) {
                ans = max(ans, j - i - 1);
            }

            i++;
        }

        return ans;
    }
};