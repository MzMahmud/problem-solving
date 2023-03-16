class Solution:
    def buildTree(self, inorder, postorder):
        inorder_index = {v:i for i, v in enumerate(inorder)}

        def build(start, end):
            if self.index < 0 or start > end:
                return None
            root = TreeNode(postorder[self.index])
            self.index -= 1
            mid = inorder_index[root.val]
            root.right = build(mid + 1, end)
            root.left = build(start, mid - 1)
            return root

        self.index = len(postorder) - 1
        return build(0, self.index)
