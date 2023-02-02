class Solution {
    private int targetPathSumCount;

    public int pathSum(TreeNode root, int targetSum) {
        targetPathSumCount = 0;
        Map<Long, Integer> pathSumCounts = new HashMap<>();
        pathSumCounts.put(0L, 1);
        dfs(root, 0, targetSum, pathSumCounts);
        return targetPathSumCount;
    }

    public void dfs(TreeNode root, long currentPathSum, long targetSum, Map<Long, Integer> pathSumCounts) {
        if (root == null) {
            return;
        }
        currentPathSum += root.val;
        long requiredPathSum = currentPathSum - targetSum;
        targetPathSumCount += pathSumCounts.getOrDefault(requiredPathSum, 0);

        pathSumCounts.compute(currentPathSum, (k, v) -> (v == null ? 0 : v) + 1);

        dfs(root.left, currentPathSum, targetSum, pathSumCounts);
        dfs(root.right, currentPathSum, targetSum, pathSumCounts);
        pathSumCounts.compute(currentPathSum, (k, v) -> v - 1);
    }
}
