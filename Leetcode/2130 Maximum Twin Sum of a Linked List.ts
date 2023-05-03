function pairSum(head: ListNode | null): number {
    let prev: ListNode | null = null;
    let slow = head, fast = head;
    while (fast !== null && fast.next !== null) {
        const _slow = slow as ListNode;
        fast = fast.next.next;
        const nextSlow = _slow.next;
        _slow.next = prev;
        prev = _slow;
        slow = nextSlow;
    }
    let maxPairSum = -Infinity;
    while (prev !== null && slow !== null) {
        maxPairSum = Math.max(maxPairSum, prev.val + slow.val);
        prev = prev.next;
        slow = slow.next;
    }
    return maxPairSum;
}
