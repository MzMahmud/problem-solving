class Solution {
    public int snakesAndLadders(int[][] board) {
        int nNodes = board.length * board.length;
        int goal = nNodes - 1;
        var adjList = buildGraph(board);
        var dist = new Integer[nNodes];
        Queue<Integer> queue = new LinkedList<>();
        queue.add(0);
        dist[0] = 0;
        while (!queue.isEmpty()) {
            int node = queue.poll();
            if (node == goal) {
                break;
            }
            for (int neighbour : adjList.get(node)) {
                if (dist[neighbour] != null) {
                    continue;
                }
                dist[neighbour] = dist[node] + 1;
                queue.add(neighbour);
            }
        }
        return dist[goal] == null ? -1 : dist[goal];
    }

    private List<Set<Integer>> buildGraph(int[][] board) {
        int nNodes = board.length * board.length;
        Map<Integer, Integer> snakesOrLaddersMap = getSnakesOrLaddersMap(board);
        List<Set<Integer>> adjList = new ArrayList<>(nNodes);
        for (int i = 0; i < nNodes; ++i) {
            Set<Integer> neighbours = new HashSet<>();
            int maxNeighbour = Math.min(i + 6, nNodes - 1);
            for (int neighbour = i + 1; neighbour <= maxNeighbour; ++neighbour) {
                neighbours.add(snakesOrLaddersMap.getOrDefault(neighbour, neighbour));
            }
            adjList.add(neighbours);
        }
        return adjList;
    }

    private Map<Integer, Integer> getSnakesOrLaddersMap(int[][] board) {
        int n = board.length;
        Map<Integer, Integer> snakesOrLaddersMap = new HashMap<>(n);
        int i = n - 1, j = 0, dj = 1, index = 0;
        while (i >= 0 & j >= 0) {
            if (board[i][j] > 0) {
                snakesOrLaddersMap.put(index, board[i][j] - 1);
            }
            ++index;
            if (j == 0 && dj == -1 || j == (n - 1) && dj == 1) {
                --i;
                dj *= -1;
            } else {
                j += dj;
            }
        }
        return snakesOrLaddersMap;
    }
}
