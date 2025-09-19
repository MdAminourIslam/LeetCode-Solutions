class Solution(object):
    def totalFruit(self, fruits):
        """
        :type fruits: List[int]
        :rtype: int
        """
        cnt = dict()
        ans = 1
        j = 0
        for i in range(len(fruits)):
            if fruits[i] in cnt:
                cnt[fruits[i]] += 1
            else:
                cnt[fruits[i]] = 1

            while len(cnt) > 2:
                cnt[fruits[j]] -= 1
                if cnt[fruits[j]] == 0:
                    del fruits[i]
                j += 1
            ans = max(ans, i - j + 1)
        return ans
