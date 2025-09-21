package LeetCode_3689;

public class Main {
    public static void main(String[] args) {
        
    }
}

class Solution {
    public long maxTotalValue(int[] nums, int k) {
        long mx = 0, mn = 1000000000;
        for (int i = 0; i < nums.length; i++) {
            mx = Math.max(mx, nums[i]);
            mn = Math.min(mn, nums[i]);
        }
        return (mx - mn) * k;
    }
}