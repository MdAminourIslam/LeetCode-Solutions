public class Solution {
    public int MinimumOperations(int[] nums) {
        int cnt = 0;

        foreach (int num in nums) {
            if (num % 3 != 0) {
                cnt += 1;
            }
        }
        return cnt;
    }
}