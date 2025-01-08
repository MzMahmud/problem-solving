public class Solution
{
    public int CountPrefixSuffixPairs(string[] words)
    {
        int count = 0;
        for (int i = 0; i < words.Length; i++)
        {
            for (int j = i + 1; j < words.Length; j++)
            {
                if (IsPrefixAndSuffix(words[i], words[j]))
                {
                    count++;
                }
            }
        }
        return count;
    }

    public static bool IsPrefixAndSuffix(string a, string b)
    {
        return b.StartsWith(a) && b.EndsWith(a);
    }
}
