class Solution {
    public int findJudge(int n, int[][] edges) {
        int[] inDegree = new int[n];
        int[] outDegree = new int[n];
        for (var edge : edges) {
            int u = edge[0] - 1, v = edge[1] - 1;
            ++outDegree[u];
            ++inDegree[v];
        }
        for (int i = 0; i < n; ++i) {
            boolean isJudge = outDegree[i] == 0 && inDegree[i] == (n - 1);
            if (isJudge) {
                return i + 1;
            }
        }
        return -1;
    }
}
