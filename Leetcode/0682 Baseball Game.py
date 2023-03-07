class Solution:
    def calPoints(self, operations):
        scores = []
        for operation in operations:
            if operation == '+':
                score = scores[-1] + scores[-2]
                scores.append(score)
            elif operation == 'D':
                scores.append(2 * scores[-1])
            elif operation == 'C':
                scores.pop()
            else:
                scores.append(int(operation))
        return sum(scores)