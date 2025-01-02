public class Solution
{
    public int FirstUniqChar(string s)
    {
        Dictionary<char, IndexCount> seenAt = [];
        for (int i = 0; i < s.Length; i++)
        {
            if (seenAt.TryGetValue(s[i], out var indexCount))
            {
                indexCount.Count++;
            }
            else
            {
                seenAt.Add(s[i], new(i, 1));
            }
        }
        int minIndex = -1;
        foreach (var (ch, indexCount) in seenAt)
        {
            if (indexCount.Count > 1) continue;
            if (minIndex == -1 || indexCount.Index < minIndex)
            {
                minIndex = indexCount.Index;
            }
        }
        return minIndex;
    }
    class IndexCount(int index, int count)
    {
        public int Index = index;
        public int Count = count;
    }
}
