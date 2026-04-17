import java.util.*;

class Solution {
    public int reverseNumber(int n) {
        int revNum = 0;
        while (n > 0) {
            revNum = revNum * 10 + (n % 10);
            n /= 10;
        }
        return revNum;
    }
    
    public int minMirrorPairDistance(int[] nums) {
        Map<Integer, Integer> indx = new HashMap<>();
        int n = nums.length;
        int answer = n;
        
        for (int i = 0; i < n; i++) {
            if (indx.containsKey(nums[i])) {
                answer = Math.min(answer, i - indx.get(nums[i]) + 1);
            }
            indx.put(reverseNumber(nums[i]), i + 1);
        }
        
        return answer == n ? -1 : answer;
    }
}