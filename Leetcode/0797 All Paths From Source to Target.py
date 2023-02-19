class Solution:
    def allPathsSourceTarget(self, graph):
        all_paths = []

        def dfs(src, dst, path):
            if src == dst:
                all_paths.append(list(path))
                return

            for child in graph[src]:
                path.append(child)
                dfs(child, dst, path)
                path.pop()

        dfs(0, len(graph) - 1, [0])
        return all_paths
