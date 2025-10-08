class Solution(object):
    def smallerNumbersThanCurrent(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        arr = sorted(nums)

        cnt = [-1 for _ in range(101)]

        for i in range(len(arr)):
            if cnt[arr[i]] == -1:
                cnt[arr[i]] = i
        
        answer = []
        for num in nums:
            answer.append(cnt[num])
        return answer