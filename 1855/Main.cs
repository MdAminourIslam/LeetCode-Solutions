public class Solution {
    public int MaxDistance(int[] nums1, int[] nums2) {
        int i = 0, j = 0, ans = 0;

        while (i < nums1.Length) {
            while (j < nums2.Length && nums2[j] >= nums1[i]) {
                j++;
            }

            if (j >= i + 1) {
                ans = Math.Max(ans, j - i - 1);
            }

            i++;
        }

        return ans;
    }
}