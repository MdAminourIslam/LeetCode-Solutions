#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> answer, cnt(100001, 0);

        for (int x : nums) {
            cnt[x] += 1;

            if (cnt[x] == 2) {
                answer.push_back(x);
            }
        }
        return answer;
    }
};