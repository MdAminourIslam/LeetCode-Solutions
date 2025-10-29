class Solution:
    def minFlips(self, a: int, b: int, c: int) -> int:
        flip = 0
        for i in range(31):
            if (a & (1 << i)) and (b & (1 << i)):
                if not (c & (1 << i)):
                    flip += 2
            elif (a & (1 << i)) or (b & (1 << i)):
                if not (c & (1 << i)):
                    flip += 1
            else:
                if (c & (1 << i)):
                    flip += 1
        return flip