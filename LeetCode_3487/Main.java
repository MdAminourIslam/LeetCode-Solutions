import java.util.Arrays;

class Solution {
    public int maxSum(int[] nums) {
        Arrays.sort(nums);
        int sum = nums[nums.length - 1];
        int mx = sum;

        for (int i = nums.length - 2; i >= 0; i--) {
            if (nums[i] != nums[i + 1]) {
                sum += nums[i];
                mx = Math.max(mx, sum);
            }
        }
        return mx;
    }
}

public class Main {
    public static void main(String[] args) {
        
    }
}