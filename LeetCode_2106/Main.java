package LeetCode_2106;

class Solution {
    public int maxTotalFruits(int[][] fruits, int startPos, int k) {
        int mx = 200002;
        int[] preSum = new int[mx];

        // Fill fruit amounts
        for (int[] fruit : fruits) {
            int pos = fruit[0] + 1;
            int amt = fruit[1];
            preSum[pos] = amt;
        }

        // Build prefix sum
        for (int i = 1; i < mx; i++) {
            preSum[i] += preSum[i - 1];
        }

        int ans = 0;
        startPos += 1;

        // Move left first, then right
        for (int i = 0; i <= k; i++) {
            int left = Math.max(startPos - i, 1);
            int right = Math.min(left + k - i, 200001);
            ans = Math.max(ans, preSum[right] - preSum[left - 1]);
        }

        // Move right first, then left
        for (int i = 0; i <= k; i++) {
            int right = Math.min(startPos + i, 200001);
            int left = Math.max(right - (k - i), 1);
            ans = Math.max(ans, preSum[right] - preSum[left - 1]);
        }

        return ans;
    }
}


public class Main {
    public static void main(String[] args) {
        
    }
}
