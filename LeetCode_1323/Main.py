class Solution:
    def maximum69Number (self, num: int) -> int:
        reverse = 0
        found = 1
        while num > 0:
            digit = num % 10
            reverse = (reverse * 10) + digit
            num = num // 10
        
        answer = 0
        while reverse > 0:
            digit = reverse % 10
            if digit == 6 and found:
                digit = 9
                found = 0
            answer = (answer * 10) + digit
            reverse = reverse // 10
        return answer

sol = Solution()
print(sol.maximum69Number(99996))

