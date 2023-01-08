class Solution {
    private int chebyshevDistance(int[] a, int[] b) {
        return Math.max(Math.abs(b[0] - a[0]), Math.abs(b[1] - a[1]));
    }

    public int minTimeToVisitAllPoints(int[][] points) {
        return IntStream.range(1, points.length)
                        .map(i -> chebyshevDistance(points[i - 1], points[i]))
                        .sum();
    }
}
