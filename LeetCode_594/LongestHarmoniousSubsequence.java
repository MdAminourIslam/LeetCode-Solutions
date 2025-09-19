package LeetCode_594;


import java.util.Arrays;
import java.util.Scanner;

class Solution {
    public int findLHS(int[] nums) {
        Arrays.sort(nums);
        int prevCount = 0, currCount = 1, result = 0;
        int prevNum = nums[0];

        for (int i = 1; i < nums.length; i++) {
            if (nums[i] == nums[i - 1]) {
                currCount++;
            } else {
                if (nums[i - 1] - 1 == prevNum) {
                    result = Math.max(result, prevCount + currCount);
                }
                prevCount = currCount;
                prevNum = nums[i - 1];
                currCount = 1;
            }
        }

        if (nums[nums.length - 1] - 1 == prevNum) {
            result = Math.max(result, prevCount + currCount);
        }

        return result;
    }
}

public class LongestHarmoniousSubsequence {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        int[] nums = new int[n];

        for (int i = 0; i < n; i++) {
            nums[i] = scanner.nextInt();
        }

        Solution sol = new Solution();
        System.out.println(sol.findLHS(nums));

        scanner.close();
    }
}
