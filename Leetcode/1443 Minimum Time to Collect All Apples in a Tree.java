class Solution {
    public int minTime(int n, int[][] edges, List<Boolean> hasApple) {
        Map<Integer, List<Integer>> childrenByNode = new HashMap<>();
        for (var edge : edges) {
            int a = edge[0];
            int b = edge[1];
            if (!childrenByNode.containsKey(a)) {
                childrenByNode.put(a, new ArrayList<>());
            }
            if (!childrenByNode.containsKey(b)) {
                childrenByNode.put(b, new ArrayList<>());
            }
            childrenByNode.get(a).add(b);
            childrenByNode.get(b).add(a);
        }
        Integer timeToGetApple = minTimeToGetApple(0, -1, childrenByNode, hasApple);
        return timeToGetApple == null ? 0 : timeToGetApple;
    }

    private Integer minTimeToGetApple(int root, int parent, Map<Integer, List<Integer>> childrenByNode, List<Boolean> hasApple) {
        Integer time = hasApple.get(root) ? 0 : null;
        for (int child : childrenByNode.getOrDefault(root, List.of())) {
            if (child == parent) {
                continue;
            }
            Integer minTimeOfChild = minTimeToGetApple(child, root, childrenByNode, hasApple);
            if (minTimeOfChild != null) {
                time = (time == null ? 0 : time) + minTimeOfChild + 2;
            }
        }
        return time;
    }
}
