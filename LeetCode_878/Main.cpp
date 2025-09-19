#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long lcm(long long a, long long b) {
        return a / __gcd(a, b) * b;
    }

    bool good(long long mid, long long a, long long b, long long n) {
        long long cnt = mid / a + mid / b ;
        long long ab = lcm(a, b);

        cnt -= (mid / ab);

        return cnt >= n;
    }

    int nthMagicalNumber(int n, int a, int b) {
        long long lo = 1, hi = 1e18; 
        long long ans = 1;

        while (lo <= hi) {
            long long mid = lo + (hi - lo) / 2;

            if (good(mid, a, b, n)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        long long mod = 1e9 + 7;
        ans %= mod;
        return (int)ans;
    }
};
