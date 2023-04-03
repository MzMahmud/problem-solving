class Solution:
    # O(n log n) time sorting + two pointer solution
    def numRescueBoats(self, people, limit):
        people.sort()
        i, j, n_boats = 0, len(people) - 1, 0
        while i <= j:
            total_weight = people[i] + people[j]
            if total_weight <= limit:
                i += 1
            n_boats += 1
            j -= 1
        return n_boats
