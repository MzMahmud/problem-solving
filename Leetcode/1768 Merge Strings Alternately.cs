public class Solution
{
    public string MergeAlternately(string word1, string word2)
    {
        var merged = new StringBuilder();
        for (int i = 0, j = 0; i < word1.Length || j < word2.Length;)
        {
            if (i < word1.Length)
            {
                merged.Append(word1[i++]);
            }
            if (j < word2.Length)
            {
                merged.Append(word2[j++]);
            }
        }
        return merged.ToString();
    }
}
