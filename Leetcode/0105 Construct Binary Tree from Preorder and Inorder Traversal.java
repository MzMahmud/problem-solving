public class Solution {
    private int preorderIndex;
    private Map<Integer, Integer> inorderIndexByValue;

    public TreeNode buildTree(int[] preorder, int[] inorder) {
        preorderIndex = 0;
        inorderIndexByValue = new HashMap<>();
        for (int i = 0; i < inorder.length; ++i) {
            inorderIndexByValue.put(inorder[i], i);
        }
        return buildTree(preorder, 0, inorder.length - 1);
    }

    public TreeNode buildTree(int[] preorder, int inorderStartIndex, int inorderEndIndex) {
        if (inorderStartIndex > inorderEndIndex || preorderIndex >= preorder.length) {
            return null;
        }
        TreeNode root = new TreeNode(preorder[preorderIndex++]);
        int inorderIndex = inorderIndexByValue.get(root.val);
        root.left = buildTree(preorder, inorderStartIndex, inorderIndex - 1);
        root.right = buildTree(preorder, inorderIndex + 1, inorderEndIndex);
        return root;
    }
}
