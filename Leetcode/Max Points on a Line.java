class Solution {
    public int maxPoints(int[][] points) {
        return IntStream.range(0, points.length)
                        .map(index -> getMaxPointOnLineWithStartingPoint(index, points))
                        .max()
                        .orElse(1);
    }

    private static int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    record Slope(int delX, int delY) {
        public Slope {
            if (delY < 0) {
                delX *= -1;
                delY *= -1;
            }
            int g = gcd(delX, delY);
            if (g != 0) {
                delX /= g;
                delY /= g;
            }
        }

        public Slope(int[] point1, int[] point2) {
            this(point1[0] - point2[0], point1[1] - point2[1]);
        }
    }


    private static int getMaxPointOnLineWithStartingPoint(int startingPointIndex, int[][] points) {
        var point = points[startingPointIndex];
        var sameSlopeToPoint =
                Arrays.stream(points)
                      .skip(startingPointIndex + 1)
                      .map(pointJ -> new Slope(point, pointJ))
                      .collect(Collectors.groupingBy(
                              Function.identity(),
                              Collectors.counting()
                      ));
        long maxPointsOnLine =
                sameSlopeToPoint.values()
                                .stream()
                                .mapToLong(x -> x)
                                .max()
                                .orElse(0);
        return 1 + (int) maxPointsOnLine;
    }
}
