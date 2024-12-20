public class Solution
{
    public int FindNonMinOrMax(int[] nums)
    {
        int min = nums[0], max = nums[0];
        foreach (int num in nums)
        {
            if (num < min)
            {
                if (min != max) return min;
                min = num;
            }
            else if (num > max)
            {
                if (min != max) return max;
                max = num;
            }
            else if (min < num && num < max)
            {
                return num;
            }
        }
        return -1;
    }
}
