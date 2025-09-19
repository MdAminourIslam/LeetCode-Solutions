#include <stdio.h>
#include <stdint.h>

long long gcd(long long a, long long b) {
    while (b != 0) {
        long long tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;
}

int isGood(long long mid, int a, int b, int c, int n) {
    long long ab = lcm(a, b);
    long long ac = lcm(a, c);
    long long bc = lcm(b, c);
    long long abc = lcm(ab, c);

    long long cnt = mid / a + mid / b + mid / c
                  - mid / ab - mid / ac - mid / bc
                  + mid / abc;

    return cnt >= n;
}

int nthUglyNumber(int n, int a, int b, int c) {
    long long lo = 1, hi = 200000000000000LL, ans = 1;

    while (lo <= hi) {
        long long mid = lo + (hi - lo) / 2;
        if (isGood(mid, a, b, c, n)) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    return (int)ans;
}
