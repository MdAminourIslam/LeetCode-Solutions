#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evenNumberBitwiseORs(vector<int>& nums) {
        int answer = 0;
        for (int num : nums) {
            answer = (num & 1 ? answer : answer | num);
        }
        return answer;
    }
};