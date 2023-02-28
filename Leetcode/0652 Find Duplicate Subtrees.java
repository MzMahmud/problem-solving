import java.util.*;

class TreeNode {
    public int val;
    public TreeNode left, right;
}

class Solution {
    private Map<TreeId, Integer> ids;
    private Map<TreeId, Integer> duplicates;
    private List<TreeNode> duplicateRoots;

    public List<TreeNode> findDuplicateSubtrees(TreeNode root) {
        ids = new HashMap<>();
        duplicates = new HashMap<>();
        duplicateRoots = new ArrayList<>();
        dfs(root);
        return duplicateRoots;
    }

    record TreeId(int leftId, int value, int rightId) {
    }

    private int dfs(TreeNode root) {
        if (root == null) {
            return 0;
        }
        var treeId = new TreeId(dfs(root.left), root.val, dfs(root.right));
        ids.putIfAbsent(treeId, ids.size() + 1);
        duplicates.compute(treeId, (k, v) -> (v == null ? 0 : v) + 1);
        if (duplicates.get(treeId) == 2) {
            duplicateRoots.add(root);
        }
        return ids.get(treeId);
    }
}