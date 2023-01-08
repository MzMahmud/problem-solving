# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.preorder_index = 0
        self.inorder_index_by_value = {}

    def buildTree(self, preorder, inorder):
        self.preorder_index = 0
        self.inorder_index_by_value = {}
        for index, value in enumerate(inorder):
            self.inorder_index_by_value[value] = index
        return self.build_tree(preorder, 0, len(inorder) - 1)

    def build_tree(self, preorder, inorder_index_start, inorder_index_end):
        has_no_value = (
                self.preorder_index == len(preorder)
                or inorder_index_start > inorder_index_end
        )
        if has_no_value:
            return None
        root = TreeNode(preorder[self.preorder_index])
        self.preorder_index += 1
        inorder_index = self.inorder_index_by_value[root.val]
        root.left = self.build_tree(preorder, inorder_index_start, inorder_index - 1)
        root.right = self.build_tree(preorder, inorder_index + 1, inorder_index_end)
        return root
