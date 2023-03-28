durations = [1, 7, 30]

class Solution:
    def mincostTickets(self, days, costs):
        cache = [None for _ in days]

        def min_cost(day_index):
            if day_index >= len(days):
                return 0
                
            if cache[day_index] is not None:
                return cache[day_index]

            cache[day_index] = float('inf')
            for duration, cost in zip(durations, costs):
                j = day_index
                while j < len(days) and days[j] < duration + days[day_index]:
                    j += 1
                cache[day_index] = min(cache[day_index], cost + min_cost(j))

            return cache[day_index]

        return min_cost(0)
