
class Solution {
    public int possibleStringCount(String word) {
        int res = 1, cnt = 1;

        for (int i = 0; i + 1 < word.length(); i++) {
            if (word.charAt(i) == word.charAt(i + 1)) {
                cnt += 1;
            } else {
                res += cnt - 1;
                cnt = 1;
            }
        }
        res += cnt - 1;
        return res;
    }
}

public class Main {
    public static void main(String[] args) {
        Solution sol = new Solution();
        String input = "aabbbaa";
        int result = sol.possibleStringCount(input);
        System.out.println("Result: " + result);
    }
}
