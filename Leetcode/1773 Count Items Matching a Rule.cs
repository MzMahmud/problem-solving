public class Solution
{
    private readonly Dictionary<string, int> KET_TO_INDEX = new()
    {
        {"type", 0},
        {"color", 1},
        {"name", 2},
    };

    public int CountMatches(IList<IList<string>> items, string ruleKey, string ruleValue)
    {
        int index = KET_TO_INDEX[ruleKey];
        return items.Count(item => item[index] == ruleValue);
    }
}
