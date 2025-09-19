class Solution(object):
    def winnerOfGame(self, colors):
        """
        :type colors: str
        :rtype: bool
        """
        alice = 0
        bob = 0
        cnta = 0
        cntb = 0
        for color in colors:
            if color == 'A':
                cnta += 1
                bob += max(0, cntb - 2)
                cntb = 0
            else:
                cntb += 1
                alice += max(0, cnta - 2)
                cnta = 0
        bob += max(0, cntb - 2)
        alice += max(0, cnta - 2)
        return alice > bob