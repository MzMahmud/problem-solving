from collections import deque


class Solution:
    def getTargetCopy(self, original_root, cloned_root, target):
        queue = deque([(original_root, cloned_root)])
        while queue:
            original, cloned = queue.popleft()
            if original == target:
                return cloned
            if original.left:
                queue.append((original.left, cloned.left))
            if original.right:
                queue.append((original.right, cloned.right))
        return None
