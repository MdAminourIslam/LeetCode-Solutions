using System.Collections.Generic;

public class Solution {
    public IList<bool> PrefixesDivBy5(int[] nums) {
        int prefix = 0;
        IList<bool> answer = new List<bool>();

        foreach (int num in nums) {
            prefix = ((prefix * 2) + num) % 5;
            answer.Add(prefix == 0);
        }
        return answer;
    }
}