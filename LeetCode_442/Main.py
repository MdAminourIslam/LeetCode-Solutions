from typing import List


class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        answer = []
        cnt = [0 for _ in range(len(nums) + 1)]

        for num in nums:
            cnt[num] += 1

            if cnt[num] == 2:
                answer.append(num)
        return answer