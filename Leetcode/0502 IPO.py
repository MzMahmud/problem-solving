import heapq


class Solution:
    def findMaximizedCapital(k, capital, profits, capitals):
        projects = list(zip(capitals, profits))
        heapq.heapify(projects)

        profit_max_heap = []
        for _ in range(k):
            while projects and projects[0][0] <= capital:
                _, profit = heapq.heappop(projects)
                # -ve taken because python heap is always min heap
                heapq.heappush(profit_max_heap, -profit)

            if not profit_max_heap:
                break

            # -ve taken because -ve is inserted in max heap
            capital += -heapq.heappop(profit_max_heap)

        return capital
