class Solution:
    def delNodes(self, root, to_delete):
        to_delete = set(to_delete)
        forest = []
        def dfs(root):
            if root is None:
                return None
            root.left = dfs(root.left) 
            root.right = dfs(root.right)
            if root.val not in to_delete:
                return root
            if root.left:
                forest.append(root.left)
            if root.right:
                forest.append(root.right)
            return None
        new_root = dfs(root)
        if new_root is not None:
            forest.append(new_root)
        return forest
