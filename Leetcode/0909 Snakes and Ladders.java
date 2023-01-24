class Solution {
    public int snakesAndLadders(int[][] board) {
        int[] flatBoard = flatten(board);
        int nNodes = flatBoard.length;
        int goal = nNodes - 1;
        var dist = new Integer[nNodes];
        Queue<Integer> queue = new LinkedList<>();
        queue.add(0);
        dist[0] = 0;
        while (!queue.isEmpty()) {
            int node = queue.poll();
            if (node == goal) {
                break;
            }
            int maxNeighbour = Math.min(node + 6, goal);
            for (int neighbour = node + 1; neighbour <= maxNeighbour; ++neighbour) {
                int next = flatBoard[neighbour] < 0 ? neighbour : flatBoard[neighbour];
                if (dist[next] != null) {
                    continue;
                }
                dist[next] = dist[node] + 1;
                queue.add(next);
            }
        }
        return dist[goal] == null ? -1 : dist[goal];
    }

    private int[] flatten(int[][] board) {
        int n = board.length;
        int[] flattened = new int[n * n];
        int i = n - 1, j = 0, dj = 1, index = 0;
        while (i >= 0 & j >= 0) {
            flattened[index++] = board[i][j] - 1;
            if (j == 0 && dj == -1 || j == (n - 1) && dj == 1) {
                --i;
                dj *= -1;
            } else {
                j += dj;
            }
        }
        return flattened;
    }
}
