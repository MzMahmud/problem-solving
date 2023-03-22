class Solution:
    def minScore(self, n, roads):
        adj_list = [[] for _ in range(n + 1)]
        for src, dst, weight in roads:
            adj_list[src].append((dst, weight))
            adj_list[dst].append((src, weight))

        return bfs(n, adj_list)


def bfs(n, adj_list):
    visited = [False] * (n + 1)
    
    queue = deque([1])
    visited[1] = True
    
    min_edge_weight = float('inf')

    while queue:
        node = queue.popleft()
        for child, weight in adj_list[node]:
            min_edge_weight = min(min_edge_weight, weight)
            if not visited[child]:
                visited[child] = True
                queue.append(child)
    
    return min_edge_weight
