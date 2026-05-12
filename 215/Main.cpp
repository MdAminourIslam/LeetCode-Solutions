#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool ok(vector<int>& nums, int k, int mid) {
        int cnt = 0;
        for (int x : nums) {
            if (mid <= x) {
                cnt += 1;
            }
        }
        return cnt >= k;
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        int lo = -10000, hi = 10000;
        int answer = hi;

        while (lo <= hi) {
            int mid = (lo + hi) / 2;

            if (ok(nums, k, mid)) {
                answer = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return answer;
    }
};

int main() {
    vector<int> nums = {3,2,3,1,2,4,5,5,6};
    int k = 4;
    cout << Solution().findKthLargest(nums, k);
}