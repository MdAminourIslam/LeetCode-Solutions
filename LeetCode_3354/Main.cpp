#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        auto ok = [&](int curr, int direction) -> bool {
            vector<int> temp = nums;  
            int n = temp.size();

            while (curr >= 0 && curr < n) {
                if (temp[curr] == 0) {
                    curr += direction;  
                } else {
                    temp[curr] -= 1;  
                    direction *= -1;      
                    curr += direction;    
                }
            }

            for (int num : temp) {
                if (num != 0) return false;
            }
            return true;
        };

        int cnt = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                if (ok(i, 1)) cnt++;   
                if (ok(i, -1)) cnt++;  
            }
        }

        return cnt;
    }
};