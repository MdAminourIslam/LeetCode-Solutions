class Solution(object):
    def maxKDivisibleComponents(self, n, edges, values, k):
        """
        :type n: int
        :type edges: List[List[int]]
        :type values: List[int]
        :type k: int
        :rtype: int
        """
        g = [[] for _ in range(n)]
        for u, v in edges:
            g[u].append(v)
            g[v].append(u)

        
        #Python এর ভিতরে যখন তুমি একটা inner function (যেমন dfs()) ব্যবহার করো,
        #সেই inner function যদি outer variable modify করতে চায়, তাহলে সেটা normally possible না।
        # use self.ans so dfs() can modify it (inner function can't change local vars)
        
        self.ans = 0

        def dfs(u, p):
            s = values[u]
            for v in g[u]:
                if v != p:
                    s += dfs(v, u)
            if s % k == 0:
                self.ans += 1
                return 0
            return s

        dfs(0, -1)
        return self.ans