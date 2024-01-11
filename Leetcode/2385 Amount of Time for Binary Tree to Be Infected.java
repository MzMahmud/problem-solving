class Solution {
    private Map<Integer, List<Integer>> graph;

    public int amountOfTime(TreeNode root, int start) {
        graph = new HashMap<>();
        setGraph(root);
        System.out.println(graph);
        Queue<Integer> queue = new LinkedList<>();
        Set<Integer> visited = new HashSet<>();
        queue.add(start);
        visited.add(start);
        int dist = 0;
        while (!queue.isEmpty()) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                var node = queue.poll();
                var neighbors = graph.getOrDefault(node, List.of());
                for (int neighbor : neighbors) {
                    if (!visited.contains(neighbor)) {
                        visited.add(neighbor);
                        queue.add(neighbor);
                    }
                }
            }
            dist++;
        }
        return dist - 1;
    }

    private void setGraph(TreeNode root) {
        if (root == null) {
            return;
        }
        if (root.left != null) {
            addEdge(root.val, root.left.val);
            addEdge(root.left.val, root.val);
            setGraph(root.left);
        }
        if (root.right != null) {
            addEdge(root.val, root.right.val);
            addEdge(root.right.val, root.val);
            setGraph(root.right);
        }
    }

    private void addEdge(int start, int end) {
        graph.compute(start, (k, v) -> v == null ? new ArrayList<>() : v).add(end);
    }
}
