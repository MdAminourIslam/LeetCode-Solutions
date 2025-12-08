class Solution:
    def sumDigitDifferences(self, nums):
        cnt = [[0] * 11 for _ in range(11)]
        answer = 0

        for num in nums:
            s = str(num)
            for j in range(len(s)):
                total = sum(cnt[j][:10])     # total previous numbers at position j
                total -= cnt[j][int(s[j])]  # remove same digit count
                
                cnt[j][int(s[j])] += 1
                answer += total

        return answer
