class Solution:
    def connect(self, root):
        if root is None:
            return root

        queue = deque([root])
        while queue:
            n_nodes_in_level = len(queue)
            prev = None
            for _ in range(n_nodes_in_level):
                curr = queue.popleft()
                if prev is not None:
                    prev.next = curr
                if curr.left is not None:
                    queue.append(curr.left)
                if curr.right is not None:
                    queue.append(curr.right)
                prev = curr

        return root
