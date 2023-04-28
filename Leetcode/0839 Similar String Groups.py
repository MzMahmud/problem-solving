class Solution:
    def numSimilarGroups(self, strs):
      adj_list = build_graph(strs)
      n = len(strs)
      visited = [False] * n
      
      def dfs(start):
        if visited[start]:
          return
        visited[start] = True
        for neighbour in adj_list[start]:
          dfs(neighbour)
        
      n_groups = 0
      for node in range(n):
        if not visited[node]:
          dfs(node)
          n_groups += 1
      return n_groups

def build_graph(strs):
  n = len(strs)
  adj_list = [[] for _ in range(n)]
  for i in range(n):
    for j in range(i + 1, n):
      if is_similar(strs[i], strs[j]):
        adj_list[i].append(j)
        adj_list[j].append(i)
  return adj_list

def is_similar(a, b):
  diff = sum(map(lambda ab: ab[0] != ab[1], zip(a, b)))
  return diff == 0 or diff == 2
