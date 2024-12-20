public class Solution
{
    public int CountKeyChanges(string s)
    {
        int change = 0;
        for (int i = 1; i < s.Length; i++)
        {
            bool changed = char.ToLower(s[i]) != char.ToLower(s[i - 1]);
            if (changed) change++;
        }
        return change;
    }
}
