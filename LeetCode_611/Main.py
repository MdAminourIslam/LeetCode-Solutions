class Solution(object):
    def triangleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums.sort()
        n = len(nums)
        result = 0

        def lower_bound(arr, target):
            lo, hi = 0, len(arr)
            while lo < hi:
                mid = lo + (hi - lo) // 2
                if arr[mid] < target:
                    lo = mid + 1
                else:
                    hi = mid
            return lo

        for i in range(n - 1):
            for j in range(i + 1, n):
                if nums[i] == 0 or nums[j] == 0:
                    continue
                s = nums[i] + nums[j]
                lo = lower_bound(nums, s)
                result += lo - j - 1

        return result
