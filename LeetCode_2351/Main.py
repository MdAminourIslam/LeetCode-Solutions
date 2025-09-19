class Solution(object):
    def repeatedCharacter(self, s):
        """
        :type s: str
        :rtype: str
        """
        cnt = {}
        for character in s:
            if character in cnt:
                return character
            cnt[character] = 1
            