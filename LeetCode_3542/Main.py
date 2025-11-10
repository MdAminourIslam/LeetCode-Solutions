class Solution(object):
    def minOperations(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        st = []
        ans = 0

        for x in nums:
            if x == 0:
                st = []  # reset the stack
                continue

            # remove bigger elements
            while st and st[-1] > x:
                st.pop()

            # if new height (increasing point)
            if not st or st[-1] < x:
                ans += 1
                st.append(x)

        return ans
