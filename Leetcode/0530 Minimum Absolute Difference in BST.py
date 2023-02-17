class Solution:
    # O(n) time, O(h) space
    # n = #nodes, h = height of the tree
    def getMinimumDifference(self, root):
        self.min_diff = float('inf')
        self.dfs(root, None)
        return self.min_diff

    def dfs(self, root, prev):
        if root is None:
            return prev
        
        prev = self.dfs(root.left, prev)
        
        if prev is not None:
            self.min_diff = min(self.min_diff, root.val - prev.val)

        return self.dfs(root.right, root)