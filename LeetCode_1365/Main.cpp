#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> arr = nums;
        sort(arr.begin(), arr.end());

        vector<int> cnt(101, -1);
        for (int i = 0; i < arr.size(); i++) {
            if (cnt[arr[i]] == -1) {
                cnt[arr[i]] = i;
            }
        }

        vector<int> answer;
        for (int num : nums) {
            answer.push_back(cnt[num]);
        }
        return answer;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {8, 1, 2, 2, 3};
    vector<int> ans = sol.smallerNumbersThanCurrent(nums);

    for (int x : ans) cout << x << " ";
    cout << endl;

    return 0;
}
