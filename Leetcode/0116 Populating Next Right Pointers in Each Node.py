class Solution:
    # O(n) time, O(n) space
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

    # O(n) time, O(1) space
    def connect(self, root):
        if root is None:
            return root

        parent, head, curr = root, root, root.left

        while curr is not None:
            curr.next = parent.right

            if parent.next is None:
                parent, head, curr = head, head.left, head.left
                continue

            curr.next.next = parent.next.left
            curr = curr.next.next
            parent = parent.next

        return root
