using System;

public class Solution {
    public int MaxDistance(int[] colors) {
        int n = colors.Length;
        int res = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (colors[i] != colors[j]) {
                    res = Math.Max(res, j - i);
                }
            }
        }
        return res;
    }
}