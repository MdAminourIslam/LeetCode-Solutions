class Solution:
    def smallestRepunitDivByK(self, k: int) -> int:
        divisor = list()
        num = 1
        cnt = 1
        while not(num % k == 0):
            if num % k in divisor:
                return -1
            divisor.append(num % k)
            num = ((num * 10) + 1) % k
            cnt += 1
        return cnt