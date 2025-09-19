
class Solution(object):
    def maxFrequency(self, nums, k):
        nums.sort()
        prefix = [0 for _ in range(len(nums) + 1)]

        for i in range(len(nums)):
            prefix[i + 1] = prefix[i] + nums[i]

        ans = 1
        for i in range(1, len(nums)):
            lo = 0
            hi = i
            cur_ans = 0
            while lo <= hi:
                mid = (lo + hi) // 2
                if self.isGood(nums, prefix, k, mid, i):
                    cur_ans = mid
                    lo = mid + 1
                else:
                    hi = mid - 1
            ans = max(ans, cur_ans + 1)  
        return ans

    def isGood(self, nums, prefix, k, mid, indx):
        # range sum = prefix[indx] - prefix[indx - mid]
        sum_range = prefix[indx] - prefix[indx - mid]
        # total ops needed = nums[indx] * mid - sum_range
        operations = nums[indx] * mid - sum_range
        return operations <= k
