UN_VISITED, VISITING, VISITED = 0, 1, 2
N_COLORS = 26
CONTIAINS_CYCLE = -1

class Solution:
    def largestPathValue(self, colors, edges):
        self.colors = colors
        n = len(colors)
        self.adj_list = [[] for _ in range(n)]
        for src, dst in edges:
            self.adj_list[src].append(dst)

        self.visit_status = [UN_VISITED] * n
        self.color_frequencies = [[0] * N_COLORS for _ in range(n)]
        
        max_freq = 0
        for node in range(n):
            freq = self.dfs(node)
            if freq == CONTIAINS_CYCLE:
                return CONTIAINS_CYCLE
            max_freq = max(max_freq, freq)
        
        return max_freq

    def dfs(self, start):
        if self.visit_status[start] == VISITING:
            return CONTIAINS_CYCLE

        if self.visit_status[start] == VISITED:
            return max(self.color_frequencies[start])
        
        self.visit_status[start] = VISITING
        node_color = ord(self.colors[start]) - ord('a') 

        for neighbour in self.adj_list[start]:
            if self.dfs(neighbour) == CONTIAINS_CYCLE:
                return CONTIAINS_CYCLE
            
            for color in range(N_COLORS):
                self.color_frequencies[start][color] = max(
                    self.color_frequencies[start][color],
                    self.color_frequencies[neighbour][color]
                )

        self.color_frequencies[start][node_color] += 1
        self.visit_status[start] = VISITED
        return max(self.color_frequencies[start])
      
