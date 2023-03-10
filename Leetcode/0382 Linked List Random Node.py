import random


class Solution:
    """
    Reservoir Sampling
    O(n) time, O(k) space
    can be used to find k random numbers from a stream of unknown size
    """

    def __init__(self, head):
        self.head = head

    def getRandom(self):
        scope, value = 1, self.head.val
        curr = self.head
        while curr:
            if random.random() < (1/scope):
                value = curr.val
            scope += 1
            curr = curr.next
        return value
