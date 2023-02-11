RED, BLUE = 0, 1
INF = float("inf")

class Solution:
    def shortestAlternatingPaths(self, n, red_edges, blue_edges):
        adj_list = [[[], []] for _ in range(n)]
        for u, v in red_edges:
            adj_list[u][RED].append(v)
        for u, v in blue_edges:
            adj_list[u][BLUE].append(v)
            
        dist_start_red = dfs(0, adj_list, RED)
        dist_start_blue = dfs(0, adj_list, BLUE)
        
        dist_min = map(min, zip(dist_start_red, dist_start_blue))
        inf_removed = map(lambda d : -1 if d is INF else d, dist_min)
        return list(inf_removed)



def dfs(root, adj_list, color):
    dist = [INF for _ in adj_list]
    visited = [[False, False] for _ in dist]

    queue = deque([(root, color)])
    dist[root] = 0
    visited[root][color] = True
    distance = 1
    while queue:
        nodes_in_level = len(queue)

        for _ in range(nodes_in_level):
            node, color = queue.popleft()
            next_color = BLUE if color == RED else RED

            for neighbour in adj_list[node][color]:
                if visited[neighbour][color]:
                    continue
                
                visited[neighbour][color] = True
                dist[neighbour] = min(dist[neighbour], distance)
                queue.append((neighbour, next_color))

        distance += 1

    return dist
