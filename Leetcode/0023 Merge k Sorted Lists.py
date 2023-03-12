class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        min_values = list(map(ComparableListNode, filter(bool, lists)))
        heapq.heapify(min_values)
        
        head = ListNode()
        tail = head
        while min_values:
            node = heapq.heappop(min_values).list_node
            tail.next = node
            tail = node
            if node.next:
                heapq.heappush(min_values, ComparableListNode(node.next))

        return head.next


class ComparableListNode:
    def __init__(self, list_node):
        self.list_node = list_node
    
    def __lt__(self, other):
        return self.list_node.val < other.list_node.val
