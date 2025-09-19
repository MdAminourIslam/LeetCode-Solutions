#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long lcm(long long a, long long b) {
        return a / __gcd(a, b) * b;
    }

    bool good(long long mid, long long a, long long b, long long c, long long n) {
        long long cnt = mid / a + mid / b + mid / c;
        long long ab = lcm(a, b);
        long long ac = lcm(a, c);
        long long bc = lcm(b, c);
        long long abc = lcm(ab, c);

        cnt -= (mid / ab + mid / ac + mid / bc);
        cnt += mid / abc;

        return cnt >= n;
    }

    int nthUglyNumber(int n, int a, int b, int c) {
        long long lo = 1, hi = 200000000000000LL; 
        long long ans = 1;

        while (lo <= hi) {
            long long mid = lo + (hi - lo) / 2;

            if (good(mid, a, b, c, n)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return (int)ans;
    }
};
