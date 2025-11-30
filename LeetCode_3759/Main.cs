public class Solution {
    public int CountElements(int[] nums, int k) {
        Array.Sort(nums);

        int n = nums.Length;
        if (k == 0) return n;
        int cnt = 0;
        foreach (int num in nums) {
            if (num < nums[n - k]) {
                cnt += 1;
            }
        }
        return cnt;
    }
}