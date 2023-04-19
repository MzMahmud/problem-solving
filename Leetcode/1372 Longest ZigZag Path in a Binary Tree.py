class Solution:
    def longestZigZag(self, root):
        self.max_len = 0
        self.dfs(root)
        return self.max_len
    
    def dfs(self, root):
        if root is None:
            return -1, -1
        _, right = self.dfs(root.left)
        left, _ = self.dfs(root.right)
        from_root = 1 + right, 1 + left
        self.max_len = max(self.max_len, *from_root)
        return from_root 
