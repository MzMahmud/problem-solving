public class Solution
{
    private static int NVowel(char c) => "aeiou".Contains(c) ? 1 : 0;

    public int MaxVowels(string s, int k)
    {
        int vowelCount = s.Take(k).Select(NVowel).Sum();
        int maxVowelCount = vowelCount;
        for (int i = k; i < s.Length; i++)
        {
            vowelCount += NVowel(s[i]) - NVowel(s[i - k]);
            maxVowelCount = Math.Max(maxVowelCount, vowelCount);
        }
        return maxVowelCount;
    }
}
