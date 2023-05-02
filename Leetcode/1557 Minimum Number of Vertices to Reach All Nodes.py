class Solution:
    def findSmallestSetOfVertices(self, n, edges):
        in_degree = [0] * n
        for _, v in edges:
            in_degree[v] += 1
        return [node for node, in_deg in enumerate(in_degree) if in_deg == 0]
 
# without list comprehension
 class Solution:
    def findSmallestSetOfVertices(self, n, edges):
        in_degree = [0] * n
        for _, v in edges:
            in_degree[v] += 1
        min_cover = []
        for node, in_deg in enumerate(in_degree):
            if in_deg == 0:
                min_cover.append(node)
        return min_cover
