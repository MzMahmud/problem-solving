from collections import defaultdict


class Solution:
    def findDuplicateSubtrees(self, root):
        ids = {}
        duplicates = defaultdict(int)
        duplicate_roots = []

        def dfs(root):
            if root is None:
                return 0

            id = dfs(root.left), root.val, dfs(root.right)
            if id not in ids:
                ids[id] = len(ids) + 1

            duplicates[id] += 1
            if duplicates[id] == 2:
                duplicate_roots.append(root)

            return ids[id]

        dfs(root)

        return duplicate_roots
