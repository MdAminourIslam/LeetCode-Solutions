class Solution(object):
    def helper(self, word, brokenLetters):
        isBroken = False
        for ch in word:
            if ch in brokenLetters:
                isBroken = True
        return isBroken == False
    def canBeTypedWords(self, text, brokenLetters):
        """
        :type text: str
        :type brokenLetters: str
        :rtype: int
        """
        word = ""
        answer = 0
        for i in range(len(text)):
            if (text[i] == ' ') :
                answer += self.helper(word, brokenLetters)
                word = ""
            else:
                word += text[i]
        answer += self.helper(word, brokenLetters)
        return answer
        
            
            