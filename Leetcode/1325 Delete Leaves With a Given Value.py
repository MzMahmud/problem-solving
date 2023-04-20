class Solution:
    def removeLeafNodes(self, root, target):
        if is_leaf_with_target(root, target):
            return None
        root.left = self.removeLeafNodes(root.left, target)
        root.right = self.removeLeafNodes(root.right, target)
        return None if is_leaf_with_target(root, target) else root

def is_leaf_with_target(root, target):
    return root is None or (root.left is None and root.right is None and root.val == target)
