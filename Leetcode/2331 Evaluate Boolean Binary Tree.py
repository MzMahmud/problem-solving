class Solution:
    def evaluateTree(self, root):
        if root.val == 0 or root.val == 1:
            return root.val == 1
        if root.val == 2:
            return self.evaluateTree(root.left) or self.evaluateTree(root.right)
        return self.evaluateTree(root.left) and self.evaluateTree(root.right)
