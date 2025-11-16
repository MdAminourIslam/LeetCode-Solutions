public class Solution {
    public int NumSub(string s) {
        const int mod = 1000000007;
        long answer = 0;
        long consecutive = 0;
        foreach (char c in s) {
            if (c == '0') {
                answer += consecutive * (consecutive + 1) / 2;
                answer %= mod;
                consecutive = 0;
            } else {
                consecutive++;
            }
        }
        answer += consecutive * (consecutive + 1) / 2;
        answer %= mod;
        return (int)answer;
    }
}