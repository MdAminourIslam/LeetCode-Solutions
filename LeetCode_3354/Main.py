class Solution(object):

    def countValidSelections(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        answer = 0
        def ok(cur, direction):
            temp = [nums[i] for i in range(len(nums))]

            while cur >= 0 and cur < len(temp):
                if temp[cur]:
                    temp[cur] -= 1
                    direction *= -1
                    cur += direction
                else:
                    cur += direction
            
            for num in temp:
                if num:
                    return False
            return True

        for i in range(len(nums)):
            if not nums[i]:
                if ok(i, 1):
                    answer += 1
                if ok(i, -1):
                    answer += 1
        return answer

        