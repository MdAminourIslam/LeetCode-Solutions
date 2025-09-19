class Solution(object):
    def largestGoodInteger(self, num):
        """
        :type num: str
        :rtype: str
        """
        n = len(num)
        res = ""
        for i in range(n - 2):
            if num[i] == num[i + 1] and num[i] == num[i + 2]:
                res = max(res, num[i:i+3])
        return res