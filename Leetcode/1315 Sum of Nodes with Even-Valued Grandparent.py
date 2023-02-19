class Solution:
    def sumEvenGrandparent(self, root):
        return dfs(root, None, None, 0)


def dfs(root, parent, grand_parent, sum):
    if root is not None:
        if grand_parent and grand_parent.val % 2 == 0:
            sum += root.val
        sum = dfs(root.left, root, parent, sum)
        sum = dfs(root.right, root, parent, sum)
    return sum