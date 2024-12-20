public class Solution
{
    public int MinimumChairs(string s)
    {
        int count = 0, maxCount = 0;
        foreach (char ch in s)
        {
            count += ch == 'E' ? 1 : -1;
            maxCount = Math.Max(count, maxCount);
        }
        return maxCount;
    }
}
