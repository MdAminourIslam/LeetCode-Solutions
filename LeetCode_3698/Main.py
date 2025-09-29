class Solution(object):
    def isDecreasing(self, nums, dec):
        """
        dec[i] = True if nums[i..end] is strictly decreasing
        """
        n = len(nums)
        dec[n - 1] = True
        for i in range(n - 2, -1, -1):
            if nums[i] > nums[i + 1] and dec[i + 1]:
                dec[i] = True
            else:
                dec[i] = False

    def suffixSumOfArray(self, nums, suffix):
        """
        suffix[i] = sum of nums[i..end]
        """
        n = len(nums)
        suffix[n - 1] = nums[n - 1]
        for i in range(n - 2, -1, -1):
            suffix[i] = suffix[i + 1] + nums[i]

    def splitArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        dec = [False] * n
        suffix = [0] * n

        self.isDecreasing(nums, dec)
        self.suffixSumOfArray(nums, suffix)

        minimum = 10**12
        prefix_sum = nums[0]
        inc = True

        for i in range(1, n):
            if dec[i] and inc:
                minimum = min(minimum, abs(prefix_sum - suffix[i]))
            
            if nums[i] <= nums[i - 1]:
                inc = False

            prefix_sum += nums[i]

        return -1 if minimum == 10**12 else minimum


print(Solution().splitArray([1, 3, 2]))  
