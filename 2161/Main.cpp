#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void helper(vector<int>& nums, int pivot, vector<int>& answer, int flag) {
        for (int x : nums) {
            if (flag == -1) {
                if (x < pivot) {
                    answer.push_back(x);
                }
            } else if (flag == 0) {
                if (x == pivot) {
                    answer.push_back(x);
                }
            } else {
                if (x > pivot) {
                    answer.push_back(x);
                }
            }
        }
    }
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> answer;
        helper(nums, pivot, answer, -1);
        helper(nums, pivot, answer, 0);
        helper(nums, pivot, answer, 1);
        return answer;
    }
};