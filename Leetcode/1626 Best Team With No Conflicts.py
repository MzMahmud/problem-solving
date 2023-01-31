class Solution:
    def bestTeamScore(self, scores, ages):
        score_ages = [ScoreAge(age, score) for age, score in zip(ages, scores)]
        score_ages.sort()

        best_scores = [score_age.score for score_age in score_ages]
        max_best_scores = float("-inf")
        
        for i in range(len(best_scores)):
            for j in range(i - 1, -1, -1):
                if score_ages[j].score <= score_ages[i].score:
                    best_scores[i] = max(best_scores[i], score_ages[i].score + best_scores[j])

            max_best_scores = max(max_best_scores, best_scores[i])

        return max_best_scores


class ScoreAge:
    def __init__(self, age, score):
        self.age = age
        self.score = score

    def __lt__(self, other):
        return (self.age, self.score) < (other.age, other.score)