public class Solution
{
    public int GetDecimalValue(ListNode head)
    {
        int number = 0;
        ListNode? curr = head;
        while (curr != null)
        {
            number = (number << 1) | curr.val;
            curr = curr.next;
        }
        return number;
    }
}
