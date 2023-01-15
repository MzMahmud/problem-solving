class Solution {
    public int numberOfGoodPaths(int[] values, int[][] edges) {
        Map<Integer, List<Integer>> adjList = new HashMap<>(values.length);
        for (var edge : edges) {
            int u = edge[0], v = edge[1];
            adjList.computeIfAbsent(u, k -> new ArrayList<>()).add(v);
            adjList.computeIfAbsent(v, k -> new ArrayList<>()).add(u);
        }
        Map<Integer, List<Integer>> valueToNodes = new TreeMap<>();
        for (int i = 0; i < values.length; ++i) {
            valueToNodes.computeIfAbsent(values[i], k -> new ArrayList<>()).add(i);
        }
        DisjointSet disjointSet = new DisjointSet(values.length);
        int goodPaths = 0;
        for (var nodes : valueToNodes.values()) {
            for (int node : nodes) {
                for (int child : adjList.getOrDefault(node, List.of())) {
                    if (values[child] > values[node]) {
                        continue;
                    }
                    disjointSet.merge(node, child);
                }
            }
            Map<Integer, Integer> nodesByComponent = new HashMap<>();
            for (int node : nodes) {
                nodesByComponent.merge(disjointSet.getParent(node), 1, Integer::sum);
            }
            for (int nNodes : nodesByComponent.values()) {
                goodPaths += nNodes * (nNodes + 1) / 2;
            }
        }
        return goodPaths;
    }
}

class DisjointSet {
    private final int[] parents;
    private final int[] ranks;

    public DisjointSet(int size) {
        parents = new int[size];
        ranks = new int[size];
        for (int i = 0; i < parents.length; ++i) {
            parents[i] = i;
        }
    }

    public void merge(int a, int b) {
        int parentA = getParent(a);
        int parentB = getParent(b);
        if (parentA == parentB) {
            return;
        }
        if (ranks[parentA] < ranks[parentB]) {
            setParent(a, parentB);
            ++ranks[parentB];
        } else {
            setParent(b, parentA);
            ++ranks[parentA];
        }
    }

    public int getParent(int index) {
        if (index == parents[index]) {
            return index;
        }
        return parents[index] = getParent(parents[index]);
    }

    private int setParent(int index, int parent) {
        if (parents[index] == index) {
            return parents[index] = parent;
        }
        return parents[index] = setParent(parents[index], parent);
    }
}
