using System;
using System.Collections.Generic;

class Solution {
    public int ReverseNumber(int n) {
        int revNum = 0;
        while (n > 0) {
            revNum = revNum * 10 + (n % 10);
            n /= 10;
        }
        return revNum;
    }
    
    public int MinMirrorPairDistance(int[] nums) {
        Dictionary<int, int> indx = new Dictionary<int, int>();
        int n = nums.Length;
        int answer = n;
        
        for (int i = 0; i < n; i++) {
            if (indx.ContainsKey(nums[i])) {
                answer = Math.Min(answer, i - indx[nums[i]] + 1);
            }
            indx[ReverseNumber(nums[i])] = i + 1;
        }
        
        return answer == n ? -1 : answer;
    }
}