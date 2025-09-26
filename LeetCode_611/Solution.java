import java.util.Arrays;

class Solution {
    public int triangleNumber(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length;
        int result = 0;

        for (int k = n - 1; k >= 2; k--) {
            int i = 0, j = k - 1;

            while (i < j) {
                if (nums[i] + nums[j] > nums[k]) {
                    result += j - i; // all pairs (i..j-1, j, k) are valid
                    j--;
                } else {
                    i++;
                }
            }
        }
        return result;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] nums = {48, 66, 61, 46, 94, 75};
        System.out.println(sol.triangleNumber(nums)); 
    }
}
