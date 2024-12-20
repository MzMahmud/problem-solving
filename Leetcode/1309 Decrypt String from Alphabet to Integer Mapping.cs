public class Solution
{
    public string FreqAlphabets(string str)
    {
        var output = new Stack<char>();
        for (int i = str.Length - 1; i >= 0; i--)
        {
            if (str[i] == '#')
            {
                int index = str[i - 1] - '0' + 10 * (str[i - 2] - '0') - 1;
                char ch = (char)('a' + index);
                output.Push(ch);
                i -= 2;
            }
            else
            {
                int index = str[i] - '0' - 1;
                char ch = (char)('a' + index);
                output.Push(ch);
            }
        }
        return string.Join("", output);
    }
}
