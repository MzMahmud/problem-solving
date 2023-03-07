import heapq
import math


class Solution:
    def pickGifts(self, gifts, k):
        max_heap = [-gift for gift in gifts]
        heapq.heapify(max_heap)
        for _ in range(k):
            gift = -heapq.heappop(max_heap)
            gift = -int(math.sqrt(gift))
            heapq.heappush(max_heap, gift)
        return -sum(max_heap)
