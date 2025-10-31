from typing import List

class Solution:
    def getSneakyNumbers(self, nums: List[int]) -> List[int]:
        answer = []
        cnt = [0 for _ in range(101)]

        for num in nums:
            cnt[num] += 1

            if cnt[num] == 2:
                answer.append(num)
        return answer