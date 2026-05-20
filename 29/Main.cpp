#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 1) return dividend;

        if (divisor == -1) {
            if (dividend == INT_MIN) return INT_MAX;
            return -dividend;
        }
        long long n = llabs((long long)dividend);
        long long d = llabs((long long)divisor);
        int answer = 0;
        bool sign = (dividend < 0) ^ (divisor < 0);

        while (n >= d) {
            int cnt = 0;
            while (n >= (d << (cnt + 1))) {
                cnt += 1;
            }
            n -= (d << cnt);
            answer += 1 << cnt;
        }

        return (sign ? -answer : answer);
    }
};