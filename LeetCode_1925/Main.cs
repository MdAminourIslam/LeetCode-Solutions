public class Solution {
    public int CountTriples(int n) {
        int res = 0;

        for (int a = 1; a <= n; a++) {
            for (int b = 1; b <= n; b++) {
                int c = (int)Math.Sqrt(a * a + b * b);
                if (c <= n && c * c == a * a + b * b) {
                    res++;
                }
            }
        }

        return res;
    }
}