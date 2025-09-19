class Solution(object):
    def countHillValley(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        cnt = 0
        for i in range(1, n - 1):
            if not nums[i] == nums[i - 1]:
                left = nums[i]
                right = nums[i]
                
                indx = i
                while indx >= 0:
                    if nums[indx] != nums[i]:
                        left = nums[indx]
                        break
                    indx -= 1
                
                indx = i
                while indx < n:
                    if nums[indx] != nums[i]:
                        right = nums[indx]
                        break
                    indx += 1
                
                if (nums[i] > left and nums[i] > right) or (nums[i] < left and nums[i] < right):
                    print(f"i = {i} and {nums[i]}")
                    cnt += 1
        return cnt