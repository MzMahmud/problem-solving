public class Solution
{
    public int[] GetSneakyNumbers(int[] nums)
    {
        for (int i = 0; i < nums.Length; i++)
        {
          nums[i]++;
        }
        int[] sneakyNums = [0, 0];
        int sneakyNumsIndex = 0;
        for (int i = 0; i < nums.Length; i++)
        {
            int index = Math.Abs(nums[i]);
            if (nums[index] < 0)
            {
                sneakyNums[sneakyNumsIndex++] = Math.Abs(index) - 1;
            }
            nums[index] *= -1;
        }
        return sneakyNums;
    }
}
