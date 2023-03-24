FORWARD, BACKWARD = 1, 0

class Solution:
    def minReorder(self, n, connections):
        self.adj_list = [[] for _ in range(n)]
        for src, dst in connections:
            self.adj_list[src].append((dst, FORWARD))
            self.adj_list[dst].append((src, BACKWARD))
        
        self.n_parent_to_child_edges = 0    
        self.dfs(0, None)
        return self.n_parent_to_child_edges
    
    def dfs(self, root, parent):
        for child, direction in self.adj_list[root]:
            if child != parent:
                self.n_parent_to_child_edges += direction
                self.dfs(child, root)
