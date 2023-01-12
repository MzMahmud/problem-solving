class Solution {
    public int[] countSubTrees(int n, int[][] edges, String labels) {
        Map<Integer, List<Integer>> adjList = new HashMap<>();
        for (var edge : edges) {
            int u = edge[0], v = edge[1];
            adjList.computeIfAbsent(u, k -> new ArrayList<>()).add(v);
            adjList.computeIfAbsent(v, k -> new ArrayList<>()).add(u);
        }
        int[] subTreeLevels = new int[n];
        countSubTreeCharCount(0, -1, adjList, labels, subTreeLevels);
        return subTreeLevels;
    }

    private int[] countSubTreeCharCount(int root, int parent, Map<Integer, List<Integer>> adjList, String labels, int[] subTreeLevels) {
        int charIndex = labels.charAt(root) - 'a';
        int[] charCount = new int[26];
        charCount[charIndex] = 1;
        for (int child : adjList.getOrDefault(root, List.of())) {
            if (child == parent) {
                continue;
            }
            int[] childCharCount = countSubTreeCharCount(child, root, adjList, labels, subTreeLevels);
            for (int i = 0; i < charCount.length; ++i) {
                charCount[i] += childCharCount[i];
            }
        }
        subTreeLevels[root] += charCount[charIndex];
        return charCount;
    }
}
