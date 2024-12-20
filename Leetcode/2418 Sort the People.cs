public class Solution
{
    public string[] SortPeople(string[] names, int[] heights)
    {
        return names.Select((name, index) => new NameHeight(name, heights[index]))
                    .OrderBy(nameHeight => nameHeight.Height)
                    .Reverse()
                    .Select(nameHeight => nameHeight.Name)
                    .ToArray();
    }

    public record struct NameHeight(string Name, int Height);
}
