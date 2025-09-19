package LeetCode_2348;

class Solution {
    public long zeroFilledSubarray(int[] nums) {
        long cnt = 0, ans = 0;
        for (int num : nums) {
            if (num == 0) {
                cnt++;
            } else {
                ans += cnt * (cnt + 1) / 2;
                cnt = 0;
            }
        }
        ans += cnt * (cnt + 1) / 2;
        return ans;
    }
}

public class Main {
    public static void main(String[] args) {
        
    }
}
