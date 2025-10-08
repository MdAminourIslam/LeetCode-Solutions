class Solution(object):
    def answerQueries(self, nums, queries):
        """
        :type nums: List[int]
        :type queries: List[int]
        :rtype: List[int]
        """
        nums.sort()

        for i in range(1, len(nums)):
            nums[i] += nums[i - 1]
        
        answer = []

        for query in queries:

            best = 0
            lo , hi = 0, len(nums) - 1
            while lo <= hi:
                mid = (lo + hi) // 2
    
                if nums[mid] <= query:
                    best = mid
                    lo = mid + 1
                else:
                    hi = mid - 1
            if nums[0] > query:
                answer.append(0)
            else:
                answer.append(best + 1)
        return answer
    
