public class Solution {
    public int FindFinalValue(int[] nums, int original) {
        Array.Sort(nums);
        foreach (int x in nums) {
            if (x == original) { 
                original *= 2;
            }
        }
        return original;
    }
}