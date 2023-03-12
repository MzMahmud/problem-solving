class Solution {
    private static final Comparator<ListNode> compareListNode = Comparator.comparingInt(node -> node.val);
    
    public ListNode mergeKLists(ListNode[] lists) {
        var minValues = new PriorityQueue<>(compareListNode);
        for(var head : lists) {
            if(head != null) {
                minValues.add(head);
            }
        }
        ListNode head = new ListNode(0), tail = head;
        while(!minValues.isEmpty()) {
            var node = minValues.poll();
            tail.next = node;
            tail = node;
            if(node.next != null) {
                minValues.add(node.next);
            }
        }
        return head.next;
    }
}
