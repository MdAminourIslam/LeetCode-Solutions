#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLHS(vector<int> &nums) {
        map<int, int> cnt;
        for (int x : nums) {
            cnt[x]++;
        }
        int res = 0;
        for (auto &[key, val] : cnt) {
            if (cnt.count(key + 1)) {
                res = max(res, val + cnt[key + 1]);
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 3, 2, 2, 5, 2, 3, 7};
    cout << sol.findLHS(nums) << "\n";
    return 0;
}
