public class Solution {
    public bool Max(int a, int b) {
        return a > b ? a : b;
    }
    public bool IsGood(int[] nums) {
        int mx = 1;
        foreach (int x in nums) {
            mx = Max(mx, x);
        }

        int[] cnt = new int[mx + 1];

        foreach (int x in nums) {
            cnt[x] += 1;
        }

        for (int i = 1; i < mx; i++) {
            if (cnt[i] > 1 || !cnt[i]) {
                return false;
            }
        }
        return cnt[mx] == 2;
    }
}