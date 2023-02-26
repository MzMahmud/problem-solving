from functools import cache


class Solution:
    def minDistance(self, from_word, to_word):
        @cache
        def edit_distance(i, j):
            if i == 0:
                return j

            if j == 0:
                return i

            if from_word[i-1] == to_word[j-1]:
                return edit_distance(i - 1, j - 1)

            insert_cost = 1 + edit_distance(i, j - 1)
            delete_cost = 1 + edit_distance(i, j - 1)
            replace_cost = 1 + edit_distance(i, j - 1)
            return min(insert_cost, delete_cost, replace_cost)

        return edit_distance(len(from_word), len(to_word))
