package LeetCode_2351;

import java.util.Arrays;

class Solution {
    public char repeatedCharacter(String s) {
        int n = s.length();
        int[] cnt = new int[26];
        Arrays.fill(cnt, 0);
        for (int i = 0; i < n; i++) {
            if (cnt[s.charAt(i) - 'a'] > 0) {
                return s.charAt(i);
            }
            cnt[s.charAt(i) - 'a']++;
        }
        return ' ';
    }
    
}

public class Main {
    public static void main(String[] args) {
        
    }
}
