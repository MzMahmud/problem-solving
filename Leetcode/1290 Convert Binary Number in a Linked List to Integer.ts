function getDecimalValue(head: ListNode | null): number {
    let num = 0;
    while (head !== null) {
        num = (num << 1) | head.val;
        head = head.next;
    }
    return num;
}
