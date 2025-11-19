from typing import List


class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        carry = 1
        n = len(digits)
        i = n - 1
        while i >= 0 and carry > 0:
            d = digits[i] + carry
            digits[i] = d % 10
            carry = d // 10
            i -= 1
        if carry == 1:
            digits.insert(0, carry)
        return digits