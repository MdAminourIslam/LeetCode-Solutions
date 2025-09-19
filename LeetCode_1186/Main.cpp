#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        int pre_max[n], suf_max[n];
        int cur_sum = 0;
        int mx = *max_element(arr.begin(), arr.end());

        for (int i = 0; i < n; i++) {
            cur_sum += arr[i];
            if (cur_sum < 0) {
                cur_sum = 0;
            } else {
                mx = max(mx, cur_sum);
            }
            pre_max[i] = cur_sum;
        }

        cur_sum = 0;
        for (int i = n - 1; i >= 0; i--) {
            cur_sum += arr[i];
            if (cur_sum < 0) {
                cur_sum = 0;
            }
            suf_max[i] = cur_sum;
        }

        

        for (int i = 1; i + 1 < n; i++) {
            int sum = (pre_max[i - 1] + suf_max[i + 1] ? pre_max[i - 1] + suf_max[i + 1] : INT_MIN);
            mx = max(mx, sum);
        }
        return mx;
    }
};