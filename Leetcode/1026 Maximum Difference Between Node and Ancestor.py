class Solution:
    def maxAncestorDiff(self, root):
        self.max_diff = float('-inf')

        def dfs(root, min_val, max_val):
            if root is None:
                self.max_diff = max(self.max_diff, max_val - min_val)
                return
            
            min_val = min(min_val, root.val)
            max_val = max(max_val, root.val)
            
            dfs(root.left, min_val, max_val)
            dfs(root.right, min_val, max_val)

        dfs(root, root.val, root.val)
        return self.max_diff
