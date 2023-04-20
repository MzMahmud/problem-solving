class Solution:
    def widthOfBinaryTree(self, root):
        queue = deque([(root, 0)])
        max_width = 0
        while queue:
            width = queue[-1][1] - queue[0][1] + 1
            max_width = max(max_width, width)
            for _ in range(len(queue)):
                node, index = queue.popleft()
                if node.left is not None:
                    queue.append((node.left, 2 * index + 1))
                if node.right is not None:
                    queue.append((node.right, 2 * index + 2))
        return max_width
