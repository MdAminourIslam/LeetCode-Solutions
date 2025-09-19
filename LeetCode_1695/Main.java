import java.util.*;

class Solution {
    public int maximumUniqueSubarray(int[] nums) {
        int n  = nums.length;
        int[] cnt = new int[10001];
        int[] pre_sum = new int[n + 1];

        Arrays.fill(pre_sum, 0);
        Arrays.fill(cnt, 0);

        for (int i = 0; i < n; i++) {
            pre_sum[i + 1] = pre_sum[i] + nums[i];
        }

        int res = 0;
        for (int i = 1, j = 1; i <= n; i++) {
            while (cnt[nums[i - 1]] > 0) {
                cnt[nums[j - 1]]--;
                j += 1;
            }
            cnt[nums[i - 1]]++;
            res = Math.max(res, pre_sum[i] - pre_sum[j - 1]);
        }
        return res;
    }
}