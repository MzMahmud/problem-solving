class Solution:
    def postorderTraversal(self, root):
        traversal = []

        def postorder(root):
            if root is None:
                return
            postorder(root.left)
            postorder(root.right)
            traversal.append(root.val)

        postorder(root)
        return traversal
