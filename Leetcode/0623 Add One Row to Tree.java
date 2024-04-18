class Solution {
    public TreeNode addOneRow(TreeNode root, int val, int depth) {
        if (depth == 1) {
            return new TreeNode(val, root, null);
        }
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        int currDepth = 1;
        while(!q.isEmpty()) {
            ++currDepth;
            if (currDepth == depth) {
                for (var node : q) {
                   node.left = new TreeNode(val, node.left, null);
                   node.right = new TreeNode(val, null, node.right); 
                }
                break;
            }
            int size = q.size();
            for (int i = 0;i < size; i++) {
                var node = q.poll();
                if (node.left != null) q.add(node.left);
                if (node.right != null) q.add(node.right);
            }
        }
        return root;
    }
}
