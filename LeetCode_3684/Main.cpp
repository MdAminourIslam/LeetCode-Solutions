#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        set<int, greater<int>> s(begin(nums), end(nums));
        vector<int> answer;
        int count = 0;
        for (int num : s) {
            if (count == k) break;
            answer.push_back(num);
            count++;
        }
        return answer;
    }
};