package LeetCode_1201;

class Solution {
    public int nthUglyNumber(int n, int a, int b, int c) {
        long lo = 1, hi = 200000000000000L;
        long ans = 1;

        while (lo <= hi) {
            long mid = lo + (hi - lo) / 2;

            if (isGood(mid, a, b, c, n)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        return (int) ans;
    }

    private boolean isGood(long mid, long a, long b, long c, long n) {
        long ab = lcm(a, b);
        long ac = lcm(a, c);
        long bc = lcm(b, c);
        long abc = lcm(ab, c);

        long count = mid / a + mid / b + mid / c
                   - mid / ab - mid / ac - mid / bc
                   + mid / abc;

        return count >= n;
    }

    private long lcm(long a, long b) {
        return a / gcd(a, b) * b;
    }

    private long gcd(long a, long b) {
        while (b != 0) {
            long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
}

public class Main {
    public static void main(String[] args) {
        
    }
}
