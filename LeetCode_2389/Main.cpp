#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++) {
            nums[i] += nums[i - 1];
        }

        vector<int> answer;
        for (int query : queries) {
            int lo = 0, hi = nums.size() - 1, best = -1;

            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                if (nums[mid] <= query) {
                    best = mid;
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }

            answer.push_back(best + 1);
        }

        return answer;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {4, 5, 2, 1};
    vector<int> queries = {3, 10, 21};

    vector<int> ans = sol.answerQueries(nums, queries);

    for (int x : ans) cout << x << " ";
    cout << endl;

    return 0;
}
