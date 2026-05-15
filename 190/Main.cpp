#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverseBits(int n) {
        int answer = 0;
        for (int i = 31; i >= 0; i--) {
            if (n & (1 << i)) {
                answer += (1 << (31 - i));
            }
        }
        return answer;
    }
};