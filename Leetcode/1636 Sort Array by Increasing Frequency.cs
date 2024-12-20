public class Solution
{
    public int[] FrequencySort(int[] nums)
    {
        var freqs = nums.GroupBy(n => n).ToDictionary(g => g.Key, g => g.Count());
        int compareByFreq(int a, int b)
        {
            int freqDiffSign = Math.Sign(freqs[a] - freqs[b]);
            if (freqDiffSign != 0) return freqDiffSign;
            return Math.Sign(b - a);
        }
        Array.Sort(nums, compareByFreq);
        return nums;
    }
}
