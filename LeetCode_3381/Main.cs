public class Solution {
    public long MaxSubarraySum(int[] nums, int k) {
        int n = nums.Length;

        long[] prefix = new long[n + 1];
        for (int i = 1; i <= n; i++)
            prefix[i] = prefix[i - 1] + nums[i - 1];

        // minimum prefix for each remainder class
        long[] minPrefix = new long[k];
        for (int i = 0; i < k; i++)
            minPrefix[i] = long.MaxValue;

        minPrefix[0] = 0; // prefix[0]

        long ans = long.MinValue;

        for (int i = 1; i <= n; i++) {
            int rem = i % k;

            if (minPrefix[rem] != long.MaxValue) {
                long candidate = prefix[i] - minPrefix[rem];
                if (candidate > ans) ans = candidate;
            }

            // update minimum prefix for this remainder
            if (prefix[i] < minPrefix[rem])
                minPrefix[rem] = prefix[i];
        }

        return ans;
    }
}
