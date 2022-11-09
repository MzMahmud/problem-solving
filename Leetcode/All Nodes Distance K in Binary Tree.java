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
    public List<Integer> distanceK(TreeNode root, TreeNode target, int k) {
        Map<Integer, TreeNode> parentsByValue = doDfsAndPopulateParents(root, null, new HashMap<>());
        Map<Integer, Integer> distByValue = new HashMap<>();
        Queue<TreeNode> queue = new LinkedList<>();
        if (target != null) {
            queue.add(target);
            distByValue.put(target.val, 0);
        }
        List<Integer> nodesDistK = new ArrayList<>();
        while (!queue.isEmpty()) {
            TreeNode treeNode = queue.poll();
            int dist = distByValue.get(treeNode.val);
            if (dist == k) {
                nodesDistK.add(treeNode.val);
            } else if (dist > k) {
                break;
            }
            TreeNode[] children = new TreeNode[] { parentsByValue.get(treeNode.val), treeNode.left, treeNode.right };
            for (TreeNode child : children) {
                if (child == null || distByValue.containsKey(child.val)) {
                    continue;
                }
                distByValue.put(child.val, dist + 1);
                queue.add(child);
            }
        }
        return nodesDistK;
    }

    public Map<Integer, TreeNode> doDfsAndPopulateParents(TreeNode root, TreeNode parent,
            Map<Integer, TreeNode> parentsByValue) {
        if (root != null) {
            parentsByValue.put(root.val, parent);
            doDfsAndPopulateParents(root.left, root, parentsByValue);
            doDfsAndPopulateParents(root.right, root, parentsByValue);
        }
        return parentsByValue;
    }
}
