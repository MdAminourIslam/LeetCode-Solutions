package LeetCode_2419;

class Solution {
    public int longestSubarray(int[] nums) {
        int mx = nums[0];
        for (int num : nums) {
            if (num > mx) mx = num;
        }

        int cnt = 0, ans = 1;
        for (int num : nums) {
            if (num == mx) {
                cnt++;
                ans = Math.max(ans, cnt);
            } else {
                cnt = 0;
            }
        }

        return ans;
    }
}

public class Main {
    public static void main(String[] args) {
        
    }
}
