public class Solution
{
    public string DestCity(IList<IList<string>> paths)
    {
        var seen = paths.Select(srcDest => srcDest[0]).ToHashSet();
        return paths.Where(srcDest => !seen.Contains(srcDest[1]))
                    .Select(srcDest => srcDest[1])
                    .FirstOrDefault("");
    }
}
