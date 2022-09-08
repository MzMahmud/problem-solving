/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    public List<List<Integer>> levelOrder(Node root) {
        if (root == null) {
            return List.of();
        }
        List<List<Integer>> levelList = new ArrayList<>();
        Queue<Node> nodeQueue = new LinkedList<>();
        nodeQueue.add(root);
        while (!nodeQueue.isEmpty()) {
            int n = nodeQueue.size();
            List<Integer> level =
                    IntStream.range(0, n)
                             .mapToObj(index -> {
                                 Node node = nodeQueue.poll();
                                 nodeQueue.addAll(node.children);
                                 return node;
                             }).map(node -> node.val)
                             .toList();
            levelList.add(level);
        }
        return levelList;
    }
}
