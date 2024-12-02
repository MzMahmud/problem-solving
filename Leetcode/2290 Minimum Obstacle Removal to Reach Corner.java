class Solution {
    record ToNode(int i, int j, int dist) implements Comparable<ToNode> {
        @Override
        public int compareTo(ToNode other) {
            return Integer.compare(this.dist, other.dist);
        }
    }

    public int minimumObstacles(int[][] grid) {
        int n = grid.length, m = grid[0].length;
        int[][] dist = new int[n][m];
        for (int[] row : dist) Arrays.fill(row, Integer.MAX_VALUE);

        PriorityQueue<ToNode> pq = new PriorityQueue<>();
        dist[0][0] = 0;
        pq.add(new ToNode(0, 0, 0));

        while (!pq.isEmpty()) {
            ToNode current = pq.poll();
            int currI = current.i, currJ = current.j, currDist = current.dist;

            if (dist[currI][currJ] < currDist) continue;

            int[][] directions = {
                    {currI - 1, currJ}, // up
                    {currI, currJ + 1}, // right
                    {currI + 1, currJ}, // down
                    {currI, currJ - 1}  // left
            };

            for (int[] next : directions) {
                int nextI = next[0], nextJ = next[1];

                if (nextI < 0 || nextI >= n || nextJ < 0 || nextJ >= m) continue;

                int newCost = currDist + grid[nextI][nextJ];
                if (newCost < dist[nextI][nextJ]) {
                    dist[nextI][nextJ] = newCost;
                    pq.add(new ToNode(nextI, nextJ, newCost));
                }
            }
        }

        return dist[n - 1][m - 1];
    }
}
