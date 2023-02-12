from collections import defaultdict
from math import ceil


class Solution:
    def minimumFuelCost(self, roads, seats):
        adj_list = defaultdict(list)
        for src, dst in roads:
            adj_list[src].append(dst)
            adj_list[dst].append(src)
        cost, _ = dfs(0, None, adj_list, seats)
        return cost


def dfs(root, parent, adj_list, seats):
    cost, passengers = 0, 1
    for child in adj_list[root]:
        if child == parent:
            continue
        child_cost, child_passengers = dfs(child, root, adj_list, seats)
        child_to_root_cost = ceil(child_passengers/seats)
        cost += child_cost + child_to_root_cost
        passengers += child_passengers
    return cost, passengers
