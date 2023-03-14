class Solution:
    def sumNumbers(self, root):
        self.sum_all = 0
        self.dfs(root, 0)
        return self.sum_all

    def dfs(self, root, parent_value):
        if root is None:
            return

        value = parent_value * 10 + root.val

        if root.left is None and root.right is None:
            self.sum_all += value

        self.dfs(root.left, value)
        self.dfs(root.right, value)
