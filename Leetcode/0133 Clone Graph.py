class Solution:
    def cloneGraph(self, node):
        if node is None:
            return None
        return dfs(node, {})


def dfs(node, already_clonned):
    if node.val in already_clonned:
        return already_clonned[node.val]
    clonned = Node(node.val, [])
    already_clonned[clonned.val] = clonned
    for neighbor in node.neighbors:
        clonned.neighbors.append(dfs(neighbor, already_clonned))
    return clonned
