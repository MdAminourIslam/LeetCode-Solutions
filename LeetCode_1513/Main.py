class Solution:
    def numSub(self, s: str) -> int:
        answer, cnt = 0, 0
        mod = 10**9 + 7
        length = len(s)
        for i in range(length):
            if s[i] == "1":
                cnt += 1
            else:
                answer += cnt * (cnt + 1) // 2
                cnt = 0

        answer += cnt * (cnt + 1) // 2
        answer %= mod
        return answer