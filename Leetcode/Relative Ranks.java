class Solution {
    private static final Map<Integer, String> positionNameByIndex = Map.of(
            0, "Gold Medal",
            1, "Silver Medal",
            2, "Bronze Medal"
    );

    record PositionNameScore(int score, String positionName) {
        static PositionNameScore from(int index, Integer[] sortedScores) {
            return new PositionNameScore(
                    sortedScores[index],
                    positionNameByIndex.getOrDefault(index, String.valueOf(index + 1))
            );
        }
    }
    
    public String[] findRelativeRanks(int[] score) {
        Integer[] sortedScores =
                Arrays.stream(score)
                      .boxed()
                      .sorted(Comparator.reverseOrder())
                      .toArray(Integer[]::new);
        Map<Integer, String> positionNameByScore =
                IntStream.range(0, sortedScores.length)
                         .mapToObj(index -> PositionNameScore.from(index, sortedScores))
                         .collect(Collectors.toUnmodifiableMap(
                                 PositionNameScore::score,
                                 PositionNameScore::positionName
                         ));
        return Arrays.stream(score)
                     .mapToObj(positionNameByScore::get)
                     .toArray(String[]::new);
    }
}
