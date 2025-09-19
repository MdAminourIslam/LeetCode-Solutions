class Solution(object):
    def good(self, nums, k, mid):
        cnt = 0
        for i in range(mid):
            if not nums[i]:
                cnt += 1
        
        if cnt <= k:
            return True
        
        for i in range(mid, len(nums)):
            if not nums[i - mid]:
                cnt -= 1
            if not nums[i]:
                cnt += 1
            if cnt <= k:
                return True
        return False

    def longestOnes(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        lo = 0
        hi = len(nums)
        answer = 0
        while lo <= hi:
            mid = (lo + hi) // 2
            if self.good(nums, k, mid):
                answer = mid
                lo = mid + 1
            else:
                hi = mid - 1
        return answer


# Testing
sol = Solution()
nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1]
k = 3
print(sol.longestOnes(nums, k))
print(sol.longestOnes(nums = [0, 0, 0], k = 0))
print(sol.longestOnes(nums = [1, 1, 1], k = 1))