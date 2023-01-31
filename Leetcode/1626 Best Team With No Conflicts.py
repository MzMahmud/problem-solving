class Solution:
    def bestTeamScore(self, scores, ages):
        score_ages = list(zip(ages, scores))
        score_ages.sort()

        best_scores = [score for _, score in score_ages]
        max_best_scores = float("-inf")
        for i in range(len(best_scores)):
            for j in range(i - 1, -1, -1):
                if score_ages[i][1] >= score_ages[j][1]:
                    best_scores[i] = max(best_scores[i], score_ages[i][1] + best_scores[j])

            max_best_scores = max(max_best_scores, best_scores[i])

        return max_best_scores