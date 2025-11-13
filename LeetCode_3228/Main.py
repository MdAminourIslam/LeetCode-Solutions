class Solution:
    def maxOperations(self, s: str) -> int:
        ones = operation = 0
        n = len(s)

        for i in range(n - 1):
            if s[i] == '0' and s[i + 1] == '1':
                operation += ones
            
            if s[i] == '1':
                ones += 1
        if s[n - 1] == '0':
            operation += ones
        return operation