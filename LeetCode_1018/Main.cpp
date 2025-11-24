#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int prefix = 0;
        vector<bool> answer;

        for (int num : nums) {
            prefix = ((prefix * 2) + num) % 5;
            answer.push_back(prefix == 0);
        }
        return answer;
    }
};