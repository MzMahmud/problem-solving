class Solution {
    public int findCheapestPrice(int n, int[][] flights, int src, int dst, int k) {
        Map<Integer, List<int[]>> adjList = new HashMap<>(n);
        for (var flight : flights) {
            adjList.computeIfAbsent(flight[0], v -> new ArrayList<>()).add(flight);
        }
        int[] cost = new int[n];
        Arrays.fill(cost, Integer.MAX_VALUE);

        Queue<int[]> queue = new LinkedList<>();
        queue.add(new int[]{src, 0});
        int stops = 0;
        while (stops <= k && !queue.isEmpty()) {
            int nodesInLevel = queue.size();
            for (int i = 0; i < nodesInLevel; ++i) {
                var nodeCost = queue.poll();
                for (var edge : adjList.getOrDefault(nodeCost[0], List.of())) {
                    int child = edge[1];
                    int costWithEdge = edge[2] + nodeCost[1];
                    if (costWithEdge < cost[child]) {
                        cost[child] = costWithEdge;
                        queue.add(new int[]{child, cost[child]});
                    }
                }
            }
            ++stops;
        }
        return cost[dst] == Integer.MAX_VALUE ? -1 : cost[dst];
    }
}
