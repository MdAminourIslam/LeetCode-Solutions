#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> ms;
        vector<int> answer;

        for (int i = 0; i < nums.size(); i++) {
            ms.insert(nums[i]);
            if (i + 1 == k) {
                answer.push_back(*ms.rbegin());
            } else if (i >= k) {
                ms.erase(ms.find(nums[i - k]));
            }
        }
        return answer;
    }
};