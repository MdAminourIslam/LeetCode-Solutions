package LeetCode_2588;
import java.util.HashMap;


class Solution {
    public long beautifulSubarrays(int[] nums) {
        HashMap<Integer, Long> count = new HashMap<>();
        int xor = 0;
        long subArray = 0;

        count.put(0, 1L);  // Initial prefix XOR is 0

        for (int num : nums) {
            xor ^= num;

            subArray += count.getOrDefault(xor, 0L);  // Add count of current xor
            count.put(xor, count.getOrDefault(xor, 0L) + 1);  // Update freq
        }

        return subArray;
    }
}


public class Main {
    public static void main(String[] args) {
        
    }
}

