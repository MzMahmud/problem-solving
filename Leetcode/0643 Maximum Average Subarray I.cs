public class Solution
{
    public double FindMaxAverage(int[] nums, int k)
    {
        int runningSum = 0;
        for (int i = 0; i < k; i++)
        {
            runningSum += nums[i];
        }
        int maxSum = runningSum;
        for (int i = k; i < nums.Length; i++)
        {
            runningSum += nums[i] - nums[i - k];
            maxSum = Math.Max(maxSum, runningSum);
        }
        return maxSum / (k + .0);
    }
}
