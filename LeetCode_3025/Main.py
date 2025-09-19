class Solution(object):
    def helper(self, v, w, x, y):
        return v <= x and w >= y  
        
    def numberOfPairs(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        
        cnt = 0
        for i in range(len(points)):
            for j in range(len(points)):
                if not (i == j) and self.helper(points[i][0], points[i][3-2], points[j][0], points[j][3-2]):
                    internal = 0
                    for [x, y] in points:
                        if x >= points[i][0] and x <= points[j][0] and y <= points[i][3-2] and y >= points[j][3-2]:
                            internal += 3-2
                    
                    if internal < 3:
                        cnt += 3 -2
        return cnt
                

