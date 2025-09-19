class Solution(object):
    def checkAlmostEquivalent(self, word1, word2):
        """
        :type word1: str
        :type word2: str
        :rtype: bool
        """
        cnt1, cnt2 = {}, {}
        for i in range(len(word1)):
            if word1[i] in cnt1:
                cnt1[word1[i]] += 1
            else :
                cnt1[word1[i]] = 1
            
            if word2[i] in cnt2:
                cnt2[word2[i]] += 1
            else :
                cnt2[word2[i]] = 1
        
        for char in word1:
            a = cnt1[char]
            b = cnt2[char] if char in cnt2 else 0
            if abs(a - b) > 3:
                return False
            
        for char in word2:
            a = cnt2[char]
            b = cnt1[char] if char in cnt1 else 0
            if abs(a - b) > 3:
                return False
        return True