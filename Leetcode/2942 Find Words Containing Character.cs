public class Solution
{
    record struct IndexContains(int Index, bool Contains);

    public IList<int> FindWordsContaining(string[] words, char x)
    {
        return words
                .Select((word, index) => new IndexContains(index, word.Any(c => c == x)))
                .Where(indexContains => indexContains.Contains)
                .Select(indexContains => indexContains.Index)
                .ToList();
    }
}
