#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int cnt = 0;
        for (int num : nums) {
            if (num % 3) {
                cnt += 1;
            }
        }
        return cnt;
    }
};