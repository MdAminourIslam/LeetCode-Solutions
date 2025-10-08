class Solution(object):
    def good(self, spell, potions, success):
        ans = len(potions)
        lo = 0
        hi = len(potions) - 1
    
        while (lo <= hi):
            mid = (lo + hi) // 2
    
            if (spell * potions[mid] >= success):
                ans = mid
                hi = mid - 1
            else:
                lo = mid + 1
        return ans
    def successfulPairs(self, spells, potions, success):
        """
        :type spells: List[int]
        :type potions: List[int]
        :type success: int
        :rtype: List[int]
        """
        answer = []
        n = len(potions)
        potions.sort()
        for spell in spells:
            answer.append(n - self.good(spell, potions, success))
        
        return answer