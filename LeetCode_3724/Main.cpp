#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2) {
        int last = nums2.back();
        int mn = INT_MAX;
        long long sum = 0;

        for (int i = 0; i < nums1.size(); i++) {
            sum += abs(nums1[i] - nums2[i]);
            mn = min(abs(nums1[i] - last), mn);
            mn = min(abs(nums2[i] - last), mn);

            if (nums1[i] > nums2[i]) {
                swap(nums1[i], nums2[i]);
            }

            if (last >= nums1[i] && last <= nums2[i]) {
                mn = 0;
            }
        }
        
        sum += (mn ? mn + 1 : 1);
        return sum;
    }
};