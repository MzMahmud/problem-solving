public class Solution
{
    public bool IsSubsequence(string s, string t)
    {
        int sIndex = 0;
        foreach (char ch in t)
        {
            if (sIndex == s.Length) return true;
            if (ch == s[sIndex]) sIndex++;
        }
        return sIndex == s.Length;
    }
}
