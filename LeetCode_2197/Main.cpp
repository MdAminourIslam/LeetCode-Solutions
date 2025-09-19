#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];
            while (!ans.empty()) {
                int g = __gcd(ans.back(), x);
                if (g == 1) break;
                x = ans.back() / g * x; 
                ans.pop_back();
            }
            ans.push_back(x);
        }
        return ans;
    }
};



// int main() {
//     vector<int> ans = Solution().replaceNonCoprimes({6, 4, 3, 2, 7, 6, 2});
//     for (int x : ans) cout << x << " ";
// }