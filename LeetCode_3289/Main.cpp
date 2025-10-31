#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer, cnt(n - 2, 0);

        for (int x : nums) {
            cnt[x] += 1;

            if (cnt[x] == 2) {
                answer.push_back(x);
            }
        }
        return answer;
    }
};