class Solution {
    public int findMinArrowShots(int[][] points) {
        Arrays.sort(points, Comparator.comparingInt(point -> point[1]));
        int minArrowShots = 1;
        int minRightX = points[0][1];
        for (var currPoint : points) {
            if (minRightX < currPoint[0]) {
                ++minArrowShots;
                minRightX = currPoint[1];
            }
        }
        return minArrowShots;
    }
}
