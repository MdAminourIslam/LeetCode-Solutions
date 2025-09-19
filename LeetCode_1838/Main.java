package LeetCode_1838;

import java.util.Arrays;

class Solution {
    public int maxFrequency(int[] nums, int k) {
        Arrays.sort(nums);
        int n = nums.length;

        long[] prefix = new long[n + 1];
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        int ans = 1;

        for (int i = 1; i < n; i++) {
            int lo = 1, hi = i + 1, best = 1;

            while (lo <= hi) {
                int mid = (lo + hi) / 2;

                long total = prefix[i + 1] - prefix[i + 1 - mid];
                long required = (long) nums[i] * mid;

                if (required - total <= k) {
                    best = mid;
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }

            ans = Math.max(ans, best);
        }

        return ans;
    }
}

public class Main {
    public static void main(String[] args) {
        
    }
    
}