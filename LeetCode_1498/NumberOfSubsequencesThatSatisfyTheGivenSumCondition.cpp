#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    const int mod = 1e9 + 7;
    void preCompute(vector<int> &power_of_two) {
        int n = power_of_two.size();
        power_of_two[0] = 1;
        for (int i = 1; i < n; i++) {
            power_of_two[i] = (power_of_two[i - 1] * 2) % mod;
        }
    }
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> power_of_two(n);
        preCompute(power_of_two);
        int l = 0, r = n - 1;
        int subSequence = 0;
        
        while (l <= r) {
            if (nums[l] + nums[r] > target) {
                r -= 1;
            } else {
                subSequence += power_of_two[r - l];
                subSequence %= mod;
                l += 1;
            }
        }
        return subSequence;
    }
};

int main() {
    vector<int> nums = {3, 5, 6, 7};
    int target = 9;
    Solution sol;
    cout << "Answer: " << sol.numSubseq(nums, target) << endl;

    return 0;
}