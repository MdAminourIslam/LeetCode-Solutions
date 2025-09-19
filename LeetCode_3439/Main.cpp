#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        
        vector<int> pre(n + 1, 0);
        for (int i = 0, cur = 0; i < n; i++) {
            cur += endTime[i] - startTime[i];
            pre[i] = cur;
        }

        int res = 0;
        for (int i = k - 1; i < n; i++) {
            int left = i + 1 == k ? 0 : endTime[i - k];
            int right = i + 1 == n ? eventTime : startTime[i + 1];
            int sum = i + 1 == k ? pre[i] : pre[i] - pre[i - k];

            res = max(res, right - left - sum);
        }
        return res;
    }
};

int main() {
    
    return 0;
}