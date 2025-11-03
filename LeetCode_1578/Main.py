from typing import List

class Solution:
    def minCost(self, colors: str, neededTime: List[int]) -> int:
        mx = summition = neededTime[0]
        answer = 0

        for i in range(1, len(colors)):
            if colors[i] == colors[i - 1]:
                mx = max(mx, neededTime[i])
                summition += neededTime[i]
            else:
                answer += summition - mx
                summition = mx = neededTime[i]
        
        answer += summition - mx
        return answer
        
