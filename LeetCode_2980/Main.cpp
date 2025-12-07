#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasTrailingZeros(vector<int>& nums) {
        int evenCnt = 0;
        for (int num : nums) {
            if (num % 2 == 0) {
                evenCnt += 1;
            }

            if (evenCnt > 1) {
                return true;
            }
        }
        return false;
    }
};