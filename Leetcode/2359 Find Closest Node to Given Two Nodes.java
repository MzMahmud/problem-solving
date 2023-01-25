class Solution {
    public int closestMeetingNode(int[] edges, int node1, int node2) {
        int[] dist1 = new int[edges.length];
        Arrays.fill(dist1, Integer.MAX_VALUE);
        dfs(node1, -1, edges, dist1);

        int[] dist2 = new int[edges.length];
        Arrays.fill(dist2, Integer.MAX_VALUE);
        dfs(node2, -1, edges, dist2);

        int minMaxDist = Integer.MAX_VALUE, minNode = -1;
        for (int node = 0; node < edges.length; ++node) {
            int currMaxDist = Math.max(dist1[node], dist2[node]);
            if (currMaxDist < minMaxDist) {
                minMaxDist = currMaxDist;
                minNode = node;
            }
        }
        return minNode;
    }

    public void dfs(int node, int parent, int[] edges, int[] dist) {
        if (node < 0 || dist[node] != Integer.MAX_VALUE) {
            return;
        }
        dist[node] = parent == -1 ? 0 : 1 + dist[parent];
        dfs(edges[node], node, edges, dist);
    }
}