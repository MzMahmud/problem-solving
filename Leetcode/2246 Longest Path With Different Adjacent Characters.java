class Solution {
    private Map<Integer, List<Integer>> adjList;
    private String labels;
    private int longestPathLength;

    public int longestPath(int[] parents, String labels) {
        this.labels = labels;
        this.longestPathLength = 0;
        this.adjList = new HashMap<>(parents.length);
        for (int u = 0; u < parents.length; ++u) {
            int v = parents[u];
            if (v < 0) continue;
            adjList.computeIfAbsent(u, k -> new ArrayList<>()).add(v);
            adjList.computeIfAbsent(v, k -> new ArrayList<>()).add(u);
        }
        getLongestPathEndingAtRoot(0, parents[0]);
        return this.longestPathLength;
    }

    private int getLongestPathEndingAtRoot(int root, int parent) {
        char rootLabel = labels.charAt(root);
        int longestPath = 0, secondLongestPath = 0;
        for (int child : adjList.getOrDefault(root, List.of())) {
            if (child == parent) {
                continue;
            }
            int pathLengthEndingAtChild = getLongestPathEndingAtRoot(child, root);
            if (rootLabel == labels.charAt(child)) {
                continue;
            }
            if (pathLengthEndingAtChild >= longestPath) {
                secondLongestPath = longestPath;
                longestPath = pathLengthEndingAtChild;
            } else if (pathLengthEndingAtChild > secondLongestPath) {
                secondLongestPath = pathLengthEndingAtChild;
            }
        }
        longestPathLength = Math.max(longestPathLength, 1 + longestPath + secondLongestPath);
        return 1 + longestPath;
    }
}
