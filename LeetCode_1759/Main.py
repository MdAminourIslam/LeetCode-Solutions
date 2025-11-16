class Solution:
    def countHomogenous(self, s: str) -> int:
        answer = 0
        consecutive = 1
        mod = 10 ** 9 + 7

        for i in range(len(s) - 1):
            if s[i] == s[i + 1]:
                consecutive += 1
            else:
                answer += consecutive * (consecutive + 1) // 2
                answer %= mod
                consecutive = 1
        answer += consecutive * (consecutive + 1) // 2
        return answer % mod