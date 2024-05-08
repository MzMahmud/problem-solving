function doubleIt(head: ListNode | null): ListNode | null {
    let prev: ListNode | null = null;
    let curr: ListNode | null = head;
    while (curr !== null) {
        const double = 2 * curr.val;
        curr.val = double % 10; 
        if (double > 9) {
            if (prev !== null) prev.val++;
            else head = new ListNode(1, head); 
        }
        prev = curr;
        curr = curr.next;
    }
    return head;
}
