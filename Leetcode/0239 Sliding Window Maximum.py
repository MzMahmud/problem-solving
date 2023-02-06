class Solution:
    def maxSlidingWindow(self, nums, k):
        sliding_window_max = []
        decresing_queue = deque()
        for i, num in enumerate(nums):
            while decresing_queue and nums[decresing_queue[-1]] < num:
                decresing_queue.pop()

            decresing_queue.append(i)

            if (i + 1) < k:
                continue

            exiting_index = i - k
            if 0 <= exiting_index and decresing_queue[0] == exiting_index:
                decresing_queue.popleft()

            sliding_window_max.append(nums[decresing_queue[0]])

        return sliding_window_max