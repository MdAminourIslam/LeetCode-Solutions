class Solution(object):
    def sumEvenAfterQueries(self, nums, queries):
        """
        :type nums: List[int]
        :type queries: List[List[int]]
        :rtype: List[int]
        """
        
        answer = list()
        evenSum = 0
        for num in nums:
            if num % 2 == 0:
                evenSum += num
        
        for [val, indx] in queries:
            if val % 2 == 0:
                if nums[indx] % 2 == 0:
                    evenSum += val
            else:
                if nums[indx] % 2:
                    evenSum += val
                    evenSum += nums[indx]
                else:
                    evenSum -= nums[indx]
            nums[indx] += val
            answer.append(evenSum)
        return answer
sol = Solution()
print(sol.sumEvenAfterQueries( nums = [1,2,3,4], queries = [[1,0],[-3,1],[-4,0],[2,3]]))
