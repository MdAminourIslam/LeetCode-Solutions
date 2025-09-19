class Solution(object):
    def numDifferentIntegers(self, word):
        """
        :type word: str
        :rtype: int
        """
        res_set = set()
        cur = ""
        word = list(word)
        for ch in word:
            if ch.isdigit():
                cur += ch
            else:
                if len(cur) > 0:
                    num = int(cur)
                    res_set.add(num)
                cur = ""
        if len(cur) > 0:
            num = int(cur)
            res_set.add(num)
        return len(res_set)




