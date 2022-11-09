/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

class Solution {
    private final Map<Integer, TreeNode> parentsByValue = new HashMap<>();

    public List<Integer> distanceK(TreeNode root, TreeNode target, int k) {
        parentsByValue.clear();
        doDfsAndPopulateParents(root, null);

        Set<Integer> visited = new HashSet<>();
        Queue<TreeNode> queue = new LinkedList<>();
        if (target != null) {
            queue.add(target);
        }
        int dist = 0;
        while (!queue.isEmpty() && dist < k) {
            int nNodesInLevel = queue.size();
            for (int i = 0; i < nNodesInLevel; ++i) {
                var treeNode = queue.poll();
                visited.add(treeNode.val);
                var children = new TreeNode[] { parentsByValue.get(treeNode.val), treeNode.left, treeNode.right };
                for (var child : children) {
                    if (child != null && !visited.contains(child.val)) {
                        queue.add(child);
                    }
                }
            }
            ++dist;
        }
        return queue.stream()
                    .map(treeNode -> treeNode.val)
                    .toList();
    }

    public Map<Integer, TreeNode> doDfsAndPopulateParents(TreeNode root, TreeNode parent) {
        if (root != null) {
            parentsByValue.put(root.val, parent);
            doDfsAndPopulateParents(root.left, root);
            doDfsAndPopulateParents(root.right, root);
        }
        return parentsByValue;
    }
}
