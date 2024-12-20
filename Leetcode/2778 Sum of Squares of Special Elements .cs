public class Solution
{
    public int SumOfSquares(int[] nums)
    {
        return nums.Where((_, i) => nums.Length % (i + 1) == 0)
                .Select(n => n * n)
                .Sum();
    }

    public int _SumOfSquares(int[] nums)
    {
        int n = nums.Length;
        return Enumerable.Range(1, n)
                  .TakeWhile(d => d * d <= n)
                  .Where(d => n % d == 0)
                  .SelectMany<int, int>(d => d == (n / d) ? [d] : [d, n / d])
                  .Select(i => nums[i - 1] * nums[i - 1])
                  .Sum();
    }
}
