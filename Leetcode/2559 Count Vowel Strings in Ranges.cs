public class Solution
{
    public int[] VowelStrings(string[] words, int[][] queries)
    {
        var counts = new int[words.Length];
        int count = 0;
        for (int i = 0; i < words.Length; i++)
        {
            count += IsVowelStrings(words[i]) ? 1 : 0;
            counts[i] = count;
        }
        var ans = new int[queries.Length];
        int j = 0;
        foreach (var q in queries)
        {
            int l = q[0], r = q[1];
            ans[j++] = counts[r] - (l > 0 ? counts[l - 1] : 0);
        }
        return ans;
    }

    private static readonly HashSet<char> VOWELS = ['a', 'e', 'i', 'o', 'u'];

    private bool IsVowelStrings(string word)
    {
        int len = word.Length;
        if (len == 0) return true;
        return VOWELS.Contains(word[0]) && VOWELS.Contains(word[len - 1]);
    }
}
