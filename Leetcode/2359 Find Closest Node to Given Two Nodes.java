class Solution {
    public int closestMeetingNode(int[] edges, int node1, int node2) {
        Integer[] dist1 = new Integer[edges.length];
        dfs(node1, -1, edges, dist1);

        Integer[] dist2 = new Integer[edges.length];
        dfs(node2, -1, edges, dist2);

        int minMaxDist = Integer.MAX_VALUE, minNode = -1;
        for (int node = 0; node < edges.length; ++node) {
            if (dist1[node] == null || dist2[node] == null) {
                continue;
            }
            int currMaxDist = Math.max(dist1[node], dist2[node]);
            if (currMaxDist < minMaxDist) {
                minMaxDist = currMaxDist;
                minNode = node;
            }
        }
        return minNode;
    }

    public void dfs(int node, int parent, int[] edges, Integer[] dist) {
        if (dist[node] != null) {
            return;
        }
        dist[node] = parent == -1 ? 0 : 1 + dist[parent];
        if (edges[node] >= 0) {
            dfs(edges[node], node, edges, dist);
        }
    }
}
