public class Solution
{
    public string KthDistinct(string[] arr, int k)
    {
        return arr.GroupBy(n => n)
                .Where(group => group.Count() == 1)
                .Skip(k - 1)
                .Select(g => g.Key)
                .FirstOrDefault("");
    }
    
    public string _KthDistinct(string[] arr, int k)
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
