public class Solution
{
    public int ArithmeticTriplets(int[] nums, int diff)
    {
        HashSet<int> contains = [];
        int count = 0;
        foreach (int num in nums)
        {
            int prev = num - diff, prevPrev = prev - diff;
            if (contains.Contains(prev) && contains.Contains(prevPrev))
            {
                count++;
            }
            contains.Add(num);
        }
        return count;
    }
}
