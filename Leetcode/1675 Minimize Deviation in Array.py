import heapq


class Solution:
    def minimumDeviation(self, nums):
        min_value = float("inf")
        for i in range(len(nums)):
            if nums[i] % 2 == 1:
                nums[i] *= 2
            min_value = min(min_value, nums[i])

        max_heap = [-n for n in nums]
        heapq.heapify(max_heap)

        deviation = min_value - max_heap[0]
        while max_heap[0] % 2 == 0:
            max_val = -heapq.heappop(max_heap)
            deviation = min(deviation, max_val - min_value)
            reduced = max_val//2
            min_value = min(min_value, reduced)
            heapq.heappush(max_heap, -reduced)

        max_val = -heapq.heappop(max_heap)
        deviation = min(deviation, max_val - min_value)
        return deviation
