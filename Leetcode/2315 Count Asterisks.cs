public class Solution
{
    public int CountAsterisks(string s)
    {
        int totalCount = 0, runningPairCount = 0;
        bool foundBar = false;
        foreach (char ch in s)
        {
            if (ch == '*')
            {
                totalCount++;
                runningPairCount++;
            }
            else if (ch == '|')
            {
                if (foundBar)
                {
                    totalCount -= runningPairCount;
                    foundBar = false;
                }
                else
                {
                    foundBar = true;
                }
                runningPairCount = 0;
            }
        }
        return totalCount;
    }
}
