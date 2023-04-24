class Solution:
    def lastStoneWeight(self, stones):
        # used -ve to create max heap
        for i in range(len(stones)):
            stones[i] *= -1
        heapify(stones)
        while len(stones) > 1:
            y = -heappop(stones)
            x = -heappop(stones)
            if x != y:
                heappush(stones, -(y - x))
        return -stones[0] if stones else 0
