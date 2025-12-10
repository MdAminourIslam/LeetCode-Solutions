class Solution(object):
    def countPermutations(self, complexity):
        """
        :type complexity: List[int]
        :rtype: int
        """
        MOD = 10**9 + 7
        n = len(complexity)
        
        # Check unlock possibility
        root = complexity[0]
        for i in range(1, n):
            if complexity[i] <= root:
                return 0   # cannot unlock computer i
        
        # Compute (n-1)!
        res = 1
        for i in range(1, n):
            res = (res * i) % MOD
        
        return res
