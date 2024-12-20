public class Solution
{
    public bool CanAliceWin(int[] nums)
    {
        int singleDigitSum = nums.Where(IsSingleDigit).Sum();
        int doubleDigitSum = nums.Where(IsDoubleDigit).Sum();
        return singleDigitSum != doubleDigitSum;
    }

    public bool IsSingleDigit(int n) => n < 10;
    public bool IsDoubleDigit(int n) => 10 <= n && n < 100;
}
