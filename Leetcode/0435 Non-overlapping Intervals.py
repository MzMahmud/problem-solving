class Solution:
    def eraseOverlapIntervals(self, intervals):
        intervals.sort()

        last_end, removed_interval = float("-inf"), 0
        for start, end in intervals:
            is_overlapping = start < last_end
            if is_overlapping:
                last_end = min(end, last_end)
                removed_interval += 1
            else:
                last_end = end

        return removed_interval