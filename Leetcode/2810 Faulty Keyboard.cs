public class Solution
{
    public string FinalString(string s)
    {
        var output = new List<char>(s.Length);
        foreach (char ch in s)
        {
            if (ch == 'i')
            {
                output.Reverse();
            }
            else
            {
                output.Add(ch);
            }
        }
        return string.Join("", output);
    }
}
