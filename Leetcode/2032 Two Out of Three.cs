public class Solution
{
    record struct IndexCount(int Index, int Count);

    public IList<int> TwoOutOfThree(params int[][] numsArray)
    {
        Dictionary<int, IndexCount> occuranceCount = [];
        for (int index = 0; index < numsArray.Length; index++)
        {
            foreach (int num in numsArray[index])
            {
                if (occuranceCount.TryGetValue(num, out IndexCount posCount))
                {
                    if (posCount.Index != index)
                    {
                        occuranceCount[num] = new(index, posCount.Count + 1);
                    }
                }
                else
                {
                    occuranceCount[num] = new(index, 1);
                }
            }
        }
        return occuranceCount
                .Where(numCount => numCount.Value.Count >= 2)
                .Select(numCount => numCount.Key).ToList();
    }
}
