from typing import List

class Solution:
    def isOneBitCharacter(self, bits: List[int]) -> bool:
        n = len(bits) - 1
        indx = 0
        while indx < n:
            if indx + 1 < n:
                if bits[indx] == 0:
                    indx += 1
                else:
                    indx += 2
            else:
                if bits[indx] == 1:
                    return False
                else:
                    return True
        return True