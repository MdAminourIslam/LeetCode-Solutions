class Solution(object):
    def maxDistance(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: int
        """
        
        i = j = ans = 0

        while i < len(nums1):
            while j < len(nums2) and nums2[j] >= nums1[i]:
                j += 1
            
            if j >= i:
                ans = max(ans, j - i - 1)
            
            i += 1
        
        return ans
