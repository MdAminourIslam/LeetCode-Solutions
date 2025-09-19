package LeetCode_878;
class Solution {
    public int nthMagicalNumber(int n, int a, int b) {
        final int MOD = 1_000_000_007;
        long A = a, B = b;
        long LCM = lcm(A, B);

        long lo = 1, hi = (long) 1e18, ans = 1;

        while (lo <= hi) {
            long mid = lo + (hi - lo) / 2;
            long count = mid / A + mid / B - mid / LCM;

            if (count >= n) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        return (int) (ans % MOD);
    }

    private long gcd(long a, long b) {
        while (b != 0) {
            long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    private long lcm(long a, long b) {
        return a / gcd(a, b) * b;
    }
}

public class Main {
    public static void main(String[] args) {
        
    }
}
