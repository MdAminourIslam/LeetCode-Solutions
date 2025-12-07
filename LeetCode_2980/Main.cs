public class Solution {
    public bool HasTrailingZeros(int[] nums) {
        int evenCnt = 0;
        foreach (int num in nums) {
            if (num % 2 == 0) {
                evenCnt += 1;
            }

            if (evenCnt > 1) {
                return true;
            }
        }
        return false;
    }
}