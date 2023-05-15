// One Pass, O(n) time, O(1) space
function swapNodes(head: ListNode | null, k: number): ListNode | null {
    let firstNode!: ListNode, secondNode!: ListNode;
    for (let curr = head; curr !== null; curr = curr.next) {
        if (secondNode) secondNode = secondNode.next as ListNode;
        if (--k === 0) {
            firstNode = curr;
            secondNode = head as ListNode;
        }
    }
    const firstNodeVal = firstNode.val;
    firstNode.val = secondNode.val;
    secondNode.val = firstNodeVal;
    return head;
}

// Two Pass, O(n) time, O(1) space
function swapNodes(head: ListNode | null, k: number): ListNode | null {
    const n = calculateLength(head);
    let firstNode!: ListNode, secondNode!: ListNode;
    for (let curr = head, i = 0; curr != null; curr = curr.next, i++) {
        if (i === (k - 1)) {
            firstNode = curr;
        }
        if (i === (n - k)) {
            secondNode = curr;
        }
    }
    const firstNodeVal = firstNode.val;
    firstNode.val = secondNode.val;
    secondNode.val = firstNodeVal;
    return head;
}

function calculateLength(head: ListNode | null): number{
    let len = 0;
    for (let curr = head; curr != null; curr = curr.next) {
        len++;
    }
    return len;
}
