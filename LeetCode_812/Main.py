class Solution(object):
    def largestTriangleArea(self, points):
        """
        :type points: List[List[int]]
        :rtype: float
        """
        def triangleArea(A, B, C):
            return 0.5 * abs(
                A[0] * (B[1] - C[1]) +
                B[0] * (C[1] - A[1]) +
                C[0] * (A[1] - B[1])
            )
        
        n = len(points)
        maxArea = 0.0
        
        for i in range(n):
            for j in range(i + 1, n):
                for k in range(j + 1, n):
                    maxArea = max(maxArea, triangleArea(points[i], points[j], points[k]))
        
        return maxArea
