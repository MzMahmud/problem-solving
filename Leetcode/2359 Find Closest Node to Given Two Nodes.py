class Solution:
    INF = float("inf")

    def closestMeetingNode(self, edges, node1, node2):
        dist1 = [Solution.INF for _ in edges]
        Solution.dfs(node1, None, edges, dist1)

        dist2 = [Solution.INF for _ in edges]
        Solution.dfs(node2, None, edges, dist2)

        min_max_dist, min_node = Solution.INF, -1
        for node, (d1, d2) in enumerate(zip(dist1, dist2)):
            cur_max_dist = max(d1, d2)
            if cur_max_dist < min_max_dist:
                min_max_dist = cur_max_dist
                min_node = node

        return min_node

    @staticmethod
    def dfs(node, parent, edges, dist):
        if node < 0 or dist[node] is not Solution.INF:
            return

        dist[node] = 0 if parent is None else 1 + dist[parent]
        Solution.dfs(edges[node], node, edges, dist)
