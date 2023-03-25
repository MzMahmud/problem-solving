class Solution:
    def countPairs(self, n, edges):
        self.adj_list = defaultdict(list)
        for src, dst in edges:
            self.adj_list[src].append(dst)
            self.adj_list[dst].append(src)
        
        self.visited = [False] * n
        remaining_node, unreachable_pairs = n, 0
        for node in range(n):
            if not self.visited[node]:
                component_size = self.dfs(node)
                unreachable_pairs += component_size * (remaining_node - component_size)
                remaining_node -= component_size
        return unreachable_pairs
        
    def dfs(self, start):
        self.visited[start] = True
        component_size = 1
        for neighbour in self.adj_list[start]:
            if not self.visited[neighbour]:
                component_size += self.dfs(neighbour)
        return component_size
        
