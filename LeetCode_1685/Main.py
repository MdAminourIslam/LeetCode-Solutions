class Solution(object):
    def getSumAbsoluteDifferences(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        n = len(nums)
        prefix = [0] * n
        prefix[0] = nums[0]

        for i in range(1, n):
            prefix[i] = prefix[i - 1] + nums[i]

        answer = [0] * n
        for i in range(n):
            if i == 0:
                answer[i] = prefix[n - 1] - prefix[i] - nums[i] * (n - 1)
            elif i + 1 == n:
                answer[i] = nums[i] * (n - 1) - prefix[i - 1]
            else:
                answer[i] = nums[i] * i - prefix[i - 1] + prefix[n - 1] - prefix[i] - nums[i] * (n - i - 1)
        return answer
