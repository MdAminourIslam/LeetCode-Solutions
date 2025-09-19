class Solution(object):
    def sumZero(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        answer = []
        sum = n * (n - 1) // 2

        for i in range(n - 1):
            answer.append(i)
        answer.append(-sum)
        return answer