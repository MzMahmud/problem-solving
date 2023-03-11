class Solution:
    # does not modify the lsit
    # O(n log n) time, O(log n) stack space
    def sortedListToBST(self, head, end=None):
        if head is end:
            return None

        if head.next is end:
            return TreeNode(head.val)

        slow, fast = head, head
        while (fast is not end) and (fast.next is not end):
            slow = slow.next
            fast = fast.next.next

        root = TreeNode(slow.val)
        root.left = self.sortedListToBST(head, slow)
        root.right = self.sortedListToBST(slow.next, end)
        return root