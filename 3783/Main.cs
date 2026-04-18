public class Solution {
    public int reversNumbere(int n) {
        int res = 0;
        while (n > 0) {
            res = res * 10 + n % 10;
            n /= 10;
        }
        return res;
    }

    public int MirrorDistance(int n) {
        return Math.Abs(n - reversNumbere(n));
    }
}