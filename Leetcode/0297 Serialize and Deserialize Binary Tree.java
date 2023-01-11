public class Codec {
    /* Serialized with level order traversal with null nodes of leaf
     * This tree produces the following Serialization (n indicates null)
                        1
                      /  \
                     2    3
                    /\   / \
                   n n  4  5
                          / \
                         6  n
                        / \
                       n  7
                         / \
                        n  n
    * 1,2,3,null,null,4,5,null,null,6,null,null,7,null,null
    *
    * For deserialization just take the generated queue and run a level order
    * traversal like algorithm and adjust the left and right pointers accordingly.
    * */
    public String serialize(TreeNode root) {
        List<String> serializedList = new ArrayList<>();
        Queue<TreeNode> queue = new LinkedList<>();
        if (root != null) {
            queue.add(root);
        }
        while (!queue.isEmpty()) {
            TreeNode treeNode = queue.poll();
            serializedList.add(treeNode == null ? "null" : String.valueOf(treeNode.val));
            if (treeNode == null) {
                continue;
            }
            queue.add(treeNode.left);
            queue.add(treeNode.right);
        }
        return String.join(",", serializedList);
    }


    public TreeNode deserialize(String serialized) {
        List<String> leveOrder =
                Arrays.stream(serialized.split(","))
                      .filter(Predicate.not(String::isEmpty))
                      .toList();
        return deserialize(leveOrder);
    }

    private TreeNode getTreeNode(String value) {
        return "null".equals(value) ? null : new TreeNode(Integer.parseInt(value));
    }

    private TreeNode deserialize(List<String> leveOrder) {
        if (leveOrder.isEmpty()) {
            return null;
        }
        Queue<TreeNode> queue = new LinkedList<>();
        int nextItemIndex = 0;
        TreeNode root = getTreeNode(leveOrder.get(nextItemIndex++));
        queue.add(root);
        while (!queue.isEmpty()) {
            TreeNode treeNode = queue.poll();
            treeNode.left = getTreeNode(leveOrder.get(nextItemIndex++));
            treeNode.right = getTreeNode(leveOrder.get(nextItemIndex++));
            if (treeNode.left != null) {
                queue.add(treeNode.left);
            }
            if (treeNode.right != null) {
                queue.add(treeNode.right);
            }
        }
        return root;
    }
}
