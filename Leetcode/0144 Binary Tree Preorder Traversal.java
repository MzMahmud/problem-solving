public class Solution {
    public List<Integer> preorderTraversalIterative(TreeNode root) {
        List<Integer> preorder = new ArrayList<>();
        Stack<TreeNode> stack = new Stack<>();
        if (root != null) {
            stack.push(root);
        }
        while (!stack.isEmpty()) {
            var top = stack.pop();
            preorder.add(top.val);
            if (top.right != null) {
                stack.push(top.right);
            }
            if (top.left != null) {
                stack.push(top.left);
            }
        }
        return preorder;
    }
    
    public List<Integer> preorderTraversal(TreeNode root) {
        return preorderTraversal(root, new ArrayList<>());        
    }
    
    public List<Integer> preorderTraversal(TreeNode root, List<Integer> preorder) {
        if(root != null) {
            preorder.add(root.val);
            preorderTraversal(root.left, preorder);
            preorderTraversal(root.right, preorder);
        }
        return preorder;
    }
}
