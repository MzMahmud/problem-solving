class Solution:
    def findJudge(self, n, edges):
        in_minus_out_degree = [0] * (n + 1)
        for u, v in edges:
            in_minus_out_degree[u] -= 1
            in_minus_out_degree[v] += 1

        for i in range(1, n + 1):
            if in_minus_out_degree[i] == (n - 1):
                return i

        return -1
