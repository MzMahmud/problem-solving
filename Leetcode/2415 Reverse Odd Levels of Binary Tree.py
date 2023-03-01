from collections import deque


class Solution:
    def reverseOddLevels(self, root):
        queue = deque([root] if root else [])
        index = 0
        while queue:
            for _ in range(len(queue)):
                node = queue.popleft()
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
            index += 1
            if index % 2 == 0:
                continue
            level = list(queue)
            i, j = 0, len(level) - 1
            while i < j:
                level[i].val, level[j].val = level[j].val, level[i].val
                i += 1
                j -= 1
        return root
