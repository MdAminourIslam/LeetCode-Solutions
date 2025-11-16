public class Solution {
    public int CountHomogenous(string s) {
        long consecutive = 1;
        long answer = 0, mod = 1000000007;

        for (int i = 0; i + 1 < s.Length; i++) {
            if (s[i] == s[i + 1]) {
                consecutive += 1;
            } else {
                answer += consecutive * (consecutive + 1) / 2;
                answer %= mod;
                consecutive = 1;
            }
        }
        answer += consecutive * (consecutive + 1) / 2;
        answer %= mod;
        return (int) answer;
    }
}