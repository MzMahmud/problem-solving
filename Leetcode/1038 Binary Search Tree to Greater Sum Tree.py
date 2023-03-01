class Solution:
    def bstToGst(self, root):
        greater_sum = 0

        def dfs(root):
            if root is None:
                return
            
            nonlocal greater_sum

            dfs(root.right)

            greater_sum += root.val
            root.val = greater_sum
            
            dfs(root.left)

        dfs(root)
        return root
