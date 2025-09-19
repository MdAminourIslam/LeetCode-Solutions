package LeetCode_1498;

import java.util.Arrays;
import java.util.Scanner;

class Solution {
    private static final int MOD = 1000000007;

    private void preCompute(int[] powerOfTwo) {
        powerOfTwo[0] = 1;
        for (int i = 1; i < powerOfTwo.length; i++) {
            powerOfTwo[i] = (int)((powerOfTwo[i - 1] * 2L) % MOD);
        }
    }

    public int numSubseq(int[] nums, int target) {
        Arrays.sort(nums);
        int n = nums.length;
        int[] powerOfTwo = new int[n];
        preCompute(powerOfTwo);

        int left = 0, right = n - 1;
        int subSequence = 0;

        while (left <= right) {
            if (nums[left] + nums[right] > target) {
                right--;
            } else {
                subSequence = (subSequence + powerOfTwo[right - left]) % MOD;
                left++;
            }
        }

        return subSequence;
    }
}

public class NumberOfSubsequences {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Input array size and elements
        System.out.print("Enter number of elements: ");
        int n = sc.nextInt();
        int[] nums = new int[n];

        System.out.println("Enter the array elements:");
        for (int i = 0; i < n; i++) {
            nums[i] = sc.nextInt();
        }

        // Input target
        System.out.print("Enter target: ");
        int target = sc.nextInt();

        // Solve
        Solution sol = new Solution();
        int result = sol.numSubseq(nums, target);
        System.out.println("Number of valid subsequences: " + result);

        sc.close();
    }
}
