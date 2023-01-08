/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public boolean isPalindrome(ListNode head) {
        if(head == null) {
            return true;
        }
        ListNode slow = head, fast = head, prev = null;
        while(fast != null && fast.next != null) {
            ListNode nextSlow = slow.next, nextFast = fast.next.next;
            slow.next = prev;
            prev = slow;
            slow = nextSlow;
            fast = nextFast;
        }
        ListNode left = prev, right = fast == null? slow : slow.next;
        while(left != null && right != null) {
            if(left.val != right.val) {
                return false;
            }
            left = left.next;
            right = right.next;
        }
        return left == null && right == null;
    }
}
