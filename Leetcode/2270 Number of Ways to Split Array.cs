public class Solution
{
    public int WaysToSplitArray(int[] nums)
    {
        long rightSum = 0;
        foreach (int n in nums)
        {
            rightSum += n;
        }
        long leftSum = 0L;
        int splits = 0;
        for (int i = 0; i < nums.Length - 1; i++)
        {
            leftSum += nums[i];
            rightSum -= nums[i];
            if (leftSum >= rightSum)
            {
                splits++;
            }
        }
        return splits;
    }
}
