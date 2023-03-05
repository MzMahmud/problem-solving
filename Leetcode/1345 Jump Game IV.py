from collections import defaultdict, deque


class Solution:
    def minJumps(self, arr):
        indices = defaultdict(list)
        for i, val in enumerate(arr):
            indices[val].append(i)

        n, last = len(arr), len(arr) - 1
        queue = deque([0])
        visited = set([0])
        steps = 0
        while queue:
            for _ in range(len(queue)):
                node = queue.popleft()
                if node == last:
                    return steps

                for child in indices[arr[node]]:
                    if child not in visited:
                        visited.add(child)
                        queue.append(child)
                indices[arr[node]].clear()

                for child in [node - 1, node + 1]:
                    if 0 <= child < n and child not in visited:
                        visited.add(child)
                        queue.append(child)

            steps += 1

        return -1
