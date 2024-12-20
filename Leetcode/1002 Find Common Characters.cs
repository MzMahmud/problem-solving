public class Solution
{
    private static readonly int CHAR_SET_SIZE = 26;

    public IList<string> CommonChars(string[] words)
    {
        var commonCount = new int[CHAR_SET_SIZE];
        Array.Fill(commonCount, int.MaxValue);
        var currCount = new int[CHAR_SET_SIZE];
        foreach (string word in words)
        {
            Array.Fill(currCount, 0);
            foreach (char ch in word)
            {
                int charIndex = ch - 'a';
                currCount[charIndex]++;
            }
            for (int i = 0; i < CHAR_SET_SIZE; i++)
            {
                commonCount[i] = Math.Min(commonCount[i], currCount[i]);
            }
        }
        List<string> output = [];
        for (int i = 0; i < CHAR_SET_SIZE; i++)
        {
            string charStr = $"{(char)('a' + i)}";
            output.AddRange(Enumerable.Repeat(charStr, commonCount[i]));
        }
        return output;
    }
}
