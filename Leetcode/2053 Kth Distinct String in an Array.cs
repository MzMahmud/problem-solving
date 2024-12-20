public class Solution
{
    public string KthDistinct(string[] arr, int k)
    {
        Dictionary<string, int> count = [];
        foreach (var word in arr)
        {
            if (count.TryGetValue(word, out int wordCount)) count[word] = wordCount + 1;
            else count[word] = 1;
        }
        int pos = 0;
        foreach (var word in arr)
        {
            if (count[word] == 1)
            {
                if (k == ++pos)
                {
                    return word;
                }
            }
        }
        return "";
    }
}
