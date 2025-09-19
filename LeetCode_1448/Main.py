# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution(object):
    def goodNodes(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        cnt = [0]

        def dfs(mx, node):
            if not node:
                return
            if node.val >= mx:  
                cnt[0] += 1
                mx = node.val
            dfs(mx, node.left)
            dfs(mx, node.right)
        
        dfs(-100000, root)
        return cnt[0]