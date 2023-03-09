class Solution:
    def detectCycle(self, head):
        slow, fast = head, head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            if slow == fast:
                break

        if not (fast and fast.next):
            return None

        fast = head
        while slow != fast:
            slow = slow.next
            fast = fast.next

        return fast
