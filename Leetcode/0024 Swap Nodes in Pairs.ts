function swapPairs(head: ListNode | null): ListNode | null {
    if (head === null || head.next === null) {
        return head;
    }
    const nextList = swapPairs(head.next.next);
    const first = head, second = head.next;
    second.next = first;
    first.next = nextList;
    return second;
}
