public class Solution
{
    public int CountServers(int[][] grid)
    {
        int n = grid.Length, m = grid[0].Length;
        var rowCount = new int[n];
        var colCount = new int[m];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    rowCount[i]++;
                    colCount[j]++;
                }
            }
        }
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1 && (rowCount[i] > 1 || colCount[j] > 1))
                {
                    count++;
                }
            }
        }
        return count;
    }
}
