class Solution {
    public int bestTeamScore(int[] scores, int[] ages) {
        ScoreAge[] scoreAges = new ScoreAge[scores.length];
        for (int i = 0; i < scoreAges.length; ++i) {
            scoreAges[i] = new ScoreAge(scores[i], ages[i]);
        }
        Arrays.sort(scoreAges, ScoreAge.ageThenScore);
        
        int[] bestScores = new int[scores.length];
        int maxBestScores = Integer.MIN_VALUE;
        for (int i = 0; i < bestScores.length; ++i) {
            bestScores[i] = scoreAges[i].score;
            for (int j = i - 1; j >= 0; --j) {
                if (scoreAges[i].score >= scoreAges[j].score) {
                    bestScores[i] = Math.max(bestScores[i], scoreAges[i].score + bestScores[j]);
                }
            }
            maxBestScores = Math.max(maxBestScores, bestScores[i]);
        }
        return maxBestScores;
    }

    record ScoreAge(int score, int age) {
        private static final Comparator<ScoreAge> ageThenScore =
                Comparator.comparingInt(ScoreAge::age)
                          .thenComparingInt(ScoreAge::score);
    }
}