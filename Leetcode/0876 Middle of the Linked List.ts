function middleNode(head: ListNode | null): ListNode | null {
    let slow = head, fast = head;
    while (fast !== null && fast.next !== null) {
        slow = (slow as ListNode).next;
        fast = fast.next.next;
    }
    return slow;
}
