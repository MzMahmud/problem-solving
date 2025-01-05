public class Solution
{
    public string ShiftingLetters(string s, int[][] shifts)
    {
        int n = s.Length;
        var diff = new int[n];
        foreach (var shift in shifts)
        {
            int from = shift[0], to = shift[1], dir = shift[2];
            if (dir == 1)
            {
                diff[from]++;
                if (to + 1 < n)
                {
                    diff[to + 1]--;
                }
            }
            else
            {
                diff[from]--;
                if (to + 1 < n)
                {
                    diff[to + 1]++;
                }
            }
        }
        var chars = new char[n];
        int nShifts = 0;
        for (int i = 0; i < n; i++)
        {
            nShifts += diff[i];
            int newIndex = ((s[i] - 'a' + nShifts) % 26 + 26) % 26;
            chars[i] = (char)('a' + newIndex);
        }
        return new(chars);
    }
}
