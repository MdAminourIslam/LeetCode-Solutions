public class Main{
    public static void main(String[] args) {
        
    }
}

class Solution {
    public int countMaxOrSubsets(int[] nums) {
        int maxOr = 0, count = 0;
        int n = nums.length;
        int total = 1 << n;

        for (int mask = 0; mask < total; mask++) {
            int cur = 0;
            for (int i = 0; i < n; i++) {
                if ((mask & (1 << i)) != 0) {
                    cur |= nums[i];
                }
            }
            if (cur > maxOr) {
                maxOr = cur;
                count = 1;
            } else if (cur == maxOr) {
                count++;
            }
        }
        return count;
    }
}
