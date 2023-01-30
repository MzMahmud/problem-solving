class Solution {
    public List<Integer> rightSideView(TreeNode root) {
        Queue<TreeNode> queue = new LinkedList<>();
        if (root != null) {
            queue.add(root);
        }
        List<Integer> rightView = new ArrayList<>();
        while (!queue.isEmpty()) {
            int nodesInLevel = queue.size();
            TreeNode node = null;
            for (int i = 0; i < nodesInLevel; ++i) {
                node = queue.poll();
                if (node.left != null) {
                    queue.add(node.left);
                }
                if (node.right != null) {
                    queue.add(node.right);
                }
            }
            rightView.add(node.val);
        }
        return rightView;
    }
}