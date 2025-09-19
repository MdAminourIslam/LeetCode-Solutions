public class Main {

    public static void main(String[] args) {
        
    }
}

class Solution {
    public int[] getMaximumXor(int[] nums, int maximumBit) {
        int mx = (1 << maximumBit) - 1;
        int n = nums.length;
        int[] ans = new int[n];
        int[] pre_xor = new int[n];
        
        pre_xor[0] = nums[0];
        for (int i = 1; i < n; i++) {
            pre_xor[i] = pre_xor[i - 1] ^ nums[i];
        }

        for (int i = 0; i < n; i++) {
            ans[i] = pre_xor[n - i - 1] ^ mx;
        }
        return ans;
    }
}
