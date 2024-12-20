using System.Text;

public class Solution
{
    public string DecodeMessage(string key, string message)
    {
        var mappings = new char[26];
        char mapped = 'a';
        foreach (char c in key)
        {
            if (c == ' ')
            {
                continue;
            }
            int index = c - 'a';
            if (mappings[index] == 0)
            {
                mappings[index] = mapped++;
            }
        }
        var decoded = new char[message.Length];
        int i = 0;
        foreach (char c in message)
        {
            if (c == ' ')
            {
                decoded[i++] = c;
            }
            else
            {
                int index = c - 'a';
                decoded[i++] = mappings[index];
            }
        }
        return new string(decoded);
    }
}
