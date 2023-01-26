from collections import deque

INF = float('inf')


class Solution:
    def findCheapestPrice(self, n, flights, src, dst, k):
        adj_list = {}
        for flight in flights:
            if flight[0] not in adj_list:
                adj_list[flight[0]] = []
            adj_list[flight[0]].append(flight)

        costs = [INF for _ in range(n)]
        queue = deque([(src, 0)])
        stops = 0
        while stops <= k and queue:
            nodes_in_level = len(queue)
            for _ in range(nodes_in_level):
                node, node_cost = queue.popleft()
                for _, child, edge_cost in adj_list.get(node, []):
                    cost_with_edge = node_cost + edge_cost
                    if cost_with_edge < costs[child]:
                        costs[child] = cost_with_edge
                        queue.append((child, costs[child]))
            stops += 1

        return -1 if costs[dst] is INF else costs[dst]
