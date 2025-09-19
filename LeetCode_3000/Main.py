import math
class Solution(object):
    def areaOfMaxDiagonal(self, dimensions):
        """
        :type dimensions: List[List[int]]
        :rtype: int
        """
        area = 0
        diagonal = 0
        for [height, width] in dimensions:
            if math.sqrt(height * height + width * width) > diagonal:
                diagonal = math.sqrt(height * height + width * width)
                area = height * width
            elif math.sqrt(height * height + width * width) == diagonal:
                area = max(area, height * width)
        return area
        
sol = Solution()
print(sol.areaOfMaxDiagonal([[6,5],[8,6],[2,10],[8,1],[9,2],[3,5],[3,5]]))