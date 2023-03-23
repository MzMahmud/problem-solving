class Solution:
    def makeConnected(self, n, connections):
        if len(connections) < (n - 1):
            return -1

        adj_list = get_adj_list(n, connections)
        visited = [False] * n
        
        n_connected_components = 0
        for start in range(n):
            if not visited[start]:
                dfs(start, adj_list, visited)
                n_connected_components += 1
        
        return n_connected_components - 1


def get_adj_list(n, edges):
    adj_list = [[] for _ in range(n)]
    for src, dst in edges:
        adj_list[src].append(dst)
        adj_list[dst].append(src)
    return adj_list

def dfs(start, adj_list, visited):
    if visited[start]:
        return
    visited[start] = True
    for child in adj_list[start]:
        dfs(child, adj_list, visited)
