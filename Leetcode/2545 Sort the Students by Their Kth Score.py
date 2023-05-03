class Solution:
    def sortTheStudents(self, score, k):
        score.sort(key=lambda a: a[k], reverse=True);
        return score
