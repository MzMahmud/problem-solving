class Solution:
    def mergeNodes(self, head):
      left, right = head, head.next
      while right is not None:
        if right.val == 0:
          left.next = None if right.next is None else right
          left = right
        else:
          left.val += right.val
        right = right.next
      return head
    
