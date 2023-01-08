public class Solution {
    /* calculate min round for small values
     * 1  2 3 4 5 6 7 8 9 10 11 12 13 14 15
     * -1 1 1 2 2 2 3 3 3 4  4  4  5  5  5
     * This can be calculated by a recursive formula
     *      minRound(n)
     *         minRound(n - 2) && minRound(n - 3) both impossible => impossible
     *         minRound(n - 2) impossible => 1 + minRound(n - 3)
     *         minRound(n - 3) impossible => 1 + minRound(n - 2)
     *         else =>  1 + min(minRound(n - 2), minRound(n - 3))
     * Base cases:
     *      minRound(n < 0) = impossible
     *      minRound(0)     = 0
     *      minRound(1)     = impossible (because only allowed to perform 2/3 tasks)
     * This can be calculated by DP
     *
     * The DP can be avoided by pattern recognition
     * minRound(n)
     *   n < 0 or n == -1 => impossible
     *   else => ceil(n / 3)
     */

    private static final int IMPOSSIBLE = -1;

    public static int getMinRound(int occurrence) {
        if (occurrence < 0 || occurrence == 1) {
            return IMPOSSIBLE;
        }
        return (int) Math.ceil(occurrence / 3.0);
    }

    public int minimumRounds(int[] tasks) {
        var occurrenceOfDifficultyLevel =
                Arrays.stream(tasks)
                      .boxed()
                      .collect(Collectors.groupingBy(
                              Function.identity(),
                              Collectors.collectingAndThen(Collectors.counting(), Long::intValue)
                      ));
        int totalRounds = 0;
        for (var occurrence : occurrenceOfDifficultyLevel.values()) {
            int minRound = getMinRound(occurrence);
            if (minRound == IMPOSSIBLE) {
                return IMPOSSIBLE;
            }
            totalRounds += minRound;
        }
        return totalRounds;
    }
}
