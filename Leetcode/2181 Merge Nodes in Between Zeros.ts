function mergeNodes(head: ListNode){
  let left = head, right= head.next;
  while (right !== null) {
    if (right.val === 0) {
      left.next = right.next === null ? null : right;
      left = right;
    } else {
      left.val += right.val; 
    }
    right = right.next;
  }
  return head;
}
