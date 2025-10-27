class Solution(object):
    def numberOfBeams(self, bank):
        """
        :type bank: List[str]
        :rtype: int
        """
        answer = 0
        last = 0
        for floor in bank:
            cur = 0
            for i in floor:
                cur += i == '1'
            answer += last * cur
            if cur:
                last = cur
        return answer