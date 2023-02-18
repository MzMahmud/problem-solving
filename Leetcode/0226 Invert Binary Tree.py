class Solution:
    def invertTree(self, root):
        if root is not None:
            root_left = root.left
            root.left = self.invertTree(root.right)
            root.right = self.invertTree(root_left)
        return root
