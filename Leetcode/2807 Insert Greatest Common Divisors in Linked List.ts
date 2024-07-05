function insertGreatestCommonDivisors(head: ListNode | null): ListNode | null {
    let left = head!, right = left.next;
    while (right != null) {
        left.next = new ListNode(gcd(left.val, right.val), right);
        left = right;
        right = right.next;
    }
    return head;
}

function gcd(a: number, b: number): number {
    return b == 0 ? a : gcd(b, a % b);
}
