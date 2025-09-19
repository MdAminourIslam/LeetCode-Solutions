class Solution(object):
    def countMaxOrSubsets(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        total = 1 << n
        max_or = 0
        count = 0

        for mask in range(total):
            cur = 0
            for i in range(n):
                if (mask & (1 << i)) != 0:
                    cur |= nums[i]
            if cur > max_or:
                max_or = cur
                count = 1
            elif cur == max_or:
                count += 1

        return count


