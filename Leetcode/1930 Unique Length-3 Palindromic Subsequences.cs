public class Solution
{
    public int CountPalindromicSubsequence(string s)
    {
        var first = new int[26];
        Array.Fill(first, -1);
        var last = new int[26];
        for (int i = 0; i < s.Length; i++)
        {
            int chIdx = s[i] - 'a';
            if (first[chIdx] == -1)
            {
                first[chIdx] = i;
            }
            last[chIdx] = i;
        }
        int count = 0;
        for (int chIdx = 0; chIdx < 26; chIdx++)
        {
            if (first[chIdx] == -1) continue;
            int uniqueChar = 0;
            for (int i = first[chIdx] + 1; i < last[chIdx]; i++)
            {
                int idx = s[i] - 'a';
                uniqueChar |= 1 << idx;
            }
            count += int.PopCount(uniqueChar);
        }
        return count;
    }
}
