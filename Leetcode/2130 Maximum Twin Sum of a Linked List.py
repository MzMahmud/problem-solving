class Solution:
    def pairSum(self, head):
        prev, slow, fast = None, head, head
        while fast and fast.next:
            fast = fast.next.next
            next_slow = slow.next
            slow.next = prev
            prev = slow
            slow = next_slow
        max_sum = float('-inf')
        while prev and slow:
            max_sum = max(max_sum, prev.val + slow.val)
            prev = prev.next
            slow = slow.next
        return max_sum
