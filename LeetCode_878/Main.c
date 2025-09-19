#include <stdio.h>

long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;
}

int nthMagicalNumber(int n, int a, int b) {
    const int MOD = 1000000007;
    long long A = a, B = b;
    long long LCM = lcm(A, B);

    long long lo = 1, hi = 1e18, ans = 1;

    while (lo <= hi) {
        long long mid = lo + (hi - lo) / 2;
        long long count = mid / A + mid / B - mid / LCM;

        if (count >= n) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    return (int)(ans % MOD);
}

int main() {
    int n = 5, a = 2, b = 4;
    printf("%d\n", nthMagicalNumber(n, a, b));  // Output: 10
    return 0;
}
