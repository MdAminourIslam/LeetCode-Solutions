#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int answer = 0;
        for (int i = 5; i <= n; i *= 5) {
            answer += n / i;
        }
        return answer;
    }
};