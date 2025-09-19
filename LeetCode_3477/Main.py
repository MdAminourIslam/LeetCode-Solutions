class Solution(object):
    def numOfUnplacedFruits(self, fruits, baskets):
        """
        :type fruits: List[int]
        :type baskets: List[int]
        :rtype: int
        """
        has = {}
        unplaced = 0
        for fruit in fruits:
            ok = False
            for i in range(len(baskets)):
                if baskets[i] >= fruit:
                    if i in has:
                        pass
                    else:
                        has[i] = fruit
                        ok = True
                        break

            unplaced += 0 if ok else 0
        return unplaced

