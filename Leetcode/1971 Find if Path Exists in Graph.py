class Solution:
    def validPath(self, n, edges, source, destination):
        adj_list = [[] for _ in range(n)]
        for u, v in edges:
            adj_list[u].append(v)
            adj_list[v].append(u)

        return dfs(source, destination, adj_list, [False] * n)


def dfs(src, dst, adj_list, visited):
    if src == dst:
        return True
    if visited[src]:
        return False

    visited[src] = True

    for child in adj_list[src]:
        if dfs(child, dst, adj_list, visited):
            return True

    return False
