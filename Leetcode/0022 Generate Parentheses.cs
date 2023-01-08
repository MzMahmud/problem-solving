public class Solution {
    public IList<string> GenerateParenthesis(int N) {
        List<string>[] allParenthesis = new List<string>[N + 1];
        allParenthesis[0] = new List<string>(){""};
        for(int n = 1;n <= N;n++)
        {
            allParenthesis[n] = new List<string>();
            for(int k = 0;k < n;k++)
            {
                List<string> inside = allParenthesis[k];
                List<string> right  = allParenthesis[n - 1 - k];
                
                foreach(string i in inside)
                {
                    foreach(string r in right)
                    {
                        allParenthesis[n].Add($"({i}){r}");
                    }
                }
            }
        }
        return allParenthesis[N];
    }
}